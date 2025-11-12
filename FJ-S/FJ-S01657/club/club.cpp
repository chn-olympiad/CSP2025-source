#include<bits/stdc++.h>
using namespace std;
struct s{
	int x,y,z,s,t,o;
}a[100005];
int sum;
int g=0,m=0,h=0;
int u=0,p=0,q=0;
int vis[100020];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	for(int i=1;i<=t;i++){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		g=0,m=0,h=0;
		u=0,p=0,q=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].s=a[i].x-a[i].y;
			a[i].t=a[i].y-a[i].z;
			a[i].o=a[i].x-a[i].z;
			if(a[i].s>=0&&a[i].o>=0){
				u++;
				g+=a[i].x;
			}else if(a[i].s<=0&&a[i].t>=0){
				p++;
				m+=a[i].y;
			}else{
				q++;
				h+=a[i].z;
			}
		}
		sum=g+m+h;
		while(u>n/2){
			int minn=200010,flag=0;
			for(int i=1;i<=n;i++){
				if(((a[i].s<minn&&vis[i]==0))&&(a[i].s>=0&&a[i].o>=0)){
					minn=a[i].s;
					flag=i;
				}
				if(((a[i].o<minn&&vis[i]==0))&&(a[i].s>=0&&a[i].o>=0)){
					minn=a[i].o;
					flag=i;
				}
			}
			vis[flag]=1;
			sum-=minn;
			u--;
		}
		while(p>n/2){
			int minn=200010,flag=0;
			for(int i=1;i<=n;i++){
				if(((a[i].t<minn&&vis[i]==0))&&(a[i].s<=0&&a[i].t>=0)){
					minn=a[i].t;
					flag=i;
				}
				if(((-(a[i].s)<minn&&vis[i]==0))&&(a[i].s<=0&&a[i].t>=0)){
					minn=-(a[i].s);
					flag=i;
				}
			}
			vis[flag]=1;
			sum-=minn;
			p--;
		}
		while(q>n/2){
			int minn=200010,flag=0;
			for(int i=1;i<=n;i++){
				if(((-(a[i].o)<minn)&&vis[i]==0)&&(a[i].o<=0&&a[i].t<=0)){
					minn=-(a[i].o);
					flag=i;
				}
				if(((-(a[i].t)<minn&&vis[i]==0))&&(a[i].o<=0&&a[i].t<=0)){
					minn=-(a[i].t);
					flag=i;
				}
			}
			sum-=minn;
			q--;
			vis[flag]=1;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
