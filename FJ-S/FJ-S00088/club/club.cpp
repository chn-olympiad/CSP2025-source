#include<bits/stdc++.h>
using namespace std;
int n,t,s1,s2,s3;
int a[100005][3];
int vis[100005];
struct node{
	int pi,w1,w2;
}b[100005];
int c[200005];
bool pd(int x,int y){
	return abs(x)<abs(y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		s1=0,s2=0,s3=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		int sum=0;
		for(int i=1;i<=n;i++){
			int maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]){
				vis[i]=1;
				b[i].pi=1;
				b[i].w1=b[i].w2=0;
				s1++;
			}
			else if(a[i][1]==a[i][2]){
				if(maxn==a[i][1]){
					vis[i]=1;
					b[i].pi=1;
					b[i].w1=0,b[i].w2=abs(a[i][1]-a[i][3]);
					s1++;
				}
				else{
					vis[i]=3;
					b[i].pi=3;
					b[i].w1=b[i].w2=abs(a[i][3]-a[i][1]);
					s3++;
				}
			}
			else if(a[i][1]==a[i][3]){
				if(maxn==a[i][1]){
					vis[i]=1;
					b[i].pi=1;
					b[i].w2=0,b[i].w1=abs(a[i][1]-a[i][2]);
					s1++;
				}
				else{
					vis[i]=2;
					b[i].pi=2;
					b[i].w1=b[i].w2=abs(a[i][2]-a[i][3]);
					s2++;
				}
			}
			else if(a[i][2]==a[i][3]){
				if(maxn==a[i][2]){
					vis[i]=2;
					b[i].pi=2;
					b[i].w2=0,b[i].w1=abs(a[i][2]-a[i][1]);
					s2++;
				}
				else{
					vis[i]=1;
					b[i].pi=1;
					b[i].w1=b[i].w2=abs(a[i][1]-a[i][2]);
					s1++;
				}
			}
			else{
				if(maxn==a[i][1]){
					vis[i]=1;
					b[i].pi=1;
					b[i].w1=abs(a[i][1]-a[i][2]);
					b[i].w2=abs(a[i][1]-a[i][3]);
					s1++;
				}
				if(maxn==a[i][2]){
					vis[i]=2;
					b[i].pi=2;
					b[i].w1=abs(a[i][2]-a[i][1]);
					b[i].w2=abs(a[i][2]-a[i][3]);
					s2++;
				}
				if(maxn==a[i][3]){
					vis[i]=3;
					b[i].pi=3;
					b[i].w1=abs(a[i][3]-a[i][1]);
					b[i].w2=abs(a[i][3]-a[i][2]);
					s3++;
				}
			}
			sum+=maxn;
		}
		int lim=n/2;
		if(s1<=lim&&s2<=lim&&s3<=lim){
			cout<<sum<<endl;
			continue;
		}
		else{
			int num=0;
			if(s1>lim){
				for(int i=1;i<=n;i++){
					if(b[i].pi==1){
						c[++num]=b[i].w1;
						c[++num]=b[i].w2;
					}
				}
				sort(c+1,c+1+num,pd);
				for(int i=1;i<=s1-lim;i++)
					sum-=abs(c[i]);
				cout<<sum<<endl;
				continue;
			}
			else if(s2>lim){
				for(int i=1;i<=n;i++){
					if(b[i].pi==2){
						c[++num]=b[i].w1;
						c[++num]=b[i].w2;
					}
				}
				sort(c+1,c+1+num,pd);
				for(int i=1;i<=s2-lim;i++)
					sum-=abs(c[i]);
				cout<<sum<<endl;
				continue;
			}
			else{
				for(int i=1;i<=n;i++){
					if(b[i].pi==3){
						c[++num]=b[i].w1;
						c[++num]=b[i].w2;
					}
				}
				sort(c+1,c+1+num,pd);
				for(int i=1;i<=s3-lim;i++)
					sum-=abs(c[i]);
				cout<<sum<<endl;
				continue;
			}
		}
	}
	return 0;
}

