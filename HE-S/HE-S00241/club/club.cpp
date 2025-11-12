#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z;
};
long long n,ans=0,m=0,ma=0,b[100010],a1,a2,a3;
long long c[100010];
bool w=1,e=1; 
node a[100010];
long long minn=1147483647,mi;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int o=0;o<t;o++){ 
		n=0;
		ans=0;
		m=0;
		ma=0;
		b[100010]={};
		c[100010]={};
		a[100010]={};
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0){
				e=0;
			}
			if(a[i].z!=0){
				w=0;
			}
		}
		if(n==2){
			cout<<max(max(max(max(a[0].z+a[1].y,a[0].z+a[1].z),max(a[0].y+a[1].z,a[0].z+a[1].x)),max(max(a[0].y+a[1].y,a[0].y+a[1].x),max(a[0].x+a[1].x,a[0].x+a[1].y))),a[0].x+a[1].z);
			continue;
		}
		if(e){
			for(int i=0;i<n/2;i++){
				int maxn=-1147483648;
				for(int j=0;j<n;j++){
					if(a[j].x>maxn){
						maxn=a[j].x;
						ma=j;
					}
				}
				ans=ans+maxn;
				a[ma].x-=1147483648;
			}
			cout<<ans;
			continue;
		}else{
			for(int j=0;j<n/2;j++){
				long long maxn=-1147483648;
				for(int i=0;i<n;i++){
					if(a[i].x>maxn){
						maxn=a[i].x;
						ma=i;
					}
				}
				b[m]=maxn;
				ans=ans+maxn;
				a1++;
				c[m]=ma;
				m++;
				a[ma].x-=1147483648;
			}
			for(int i=0;i<n/2;i++){
				long long minn=1147483647,mi=0;
				for(int j=0;j<n/2-i;j++){
					if(a[j].x<minn){
						minn=a[j].x;
						mi=j;
					}
				}
				if(a[c[mi]].y<0&&a[c[mi]].y>a[c[mi]].x){
					ans=ans-a[c[mi]].x-1147483648;
					a[c[mi]].x+=1147483648;
				}
				if(a[c[mi]].z<0&&a[c[mi]].z>a[c[mi]].x){
					ans=ans-a[c[mi]].x-1147483648;
					a[c[mi]].x+=1147483648;
					a1--;
				}
			}
			
			for(int j=0;j<n/2;j++){
				long long maxn=-1147483648;
				for(int i=0;i<n;i++){
					if(a[i].y>maxn){
						maxn=a[i].y;
						ma=i;
					}
				}
				b[m]=maxn;
				ans=ans+maxn;
				a2++;
				c[m]=ma;
				m++;
				a[ma].y-=1147483648;
			}
			for(int i=0;i<n/2;i++){
				long long minn=1147483647,mi=0;
				for(int j=0;j<n/2-i;j++){
					if(a[j].y<minn){
						minn=a[j].y;
						mi=j;
					}
				}
				if(a[c[mi]].x<0&&a[c[mi]].x>a[c[mi]].y){
					ans=ans-a[c[mi]].y-1147483648;
					a[c[mi]].y+=1147483648;
				}
				if(a[c[mi]].z<0&&a[c[mi]].z>a[c[mi]].y){
					ans=ans-a[c[mi]].y-1147483648;
					a[c[mi]].y+=1147483648;
					a2--;
				}
			}
			
			for(int j=0;j<n/2;j++){
				long long maxn=-1147483648;
				for(int i=0;i<n;i++){
					if(a[i].z>maxn){
						maxn=a[i].z;
						ma=i;
					}
				}
				b[m]=maxn;
				ans=ans+maxn;
				a3++;
				c[m]=ma;
				m++;
				a[ma].z-=1147483648;
			}
			for(int i=0;i<n/2;i++){
				long long minn=1147483647,mi=0;
				for(int j=0;j<n/2-i;j++){
					if(a[j].z<minn){
						minn=a[j].z;
						mi=j;
					}
				}
				if(a[c[mi]].x<0&&a[c[mi]].x>a[c[mi]].z){
					ans=ans-a[c[mi]].z-1147483648;
					a[c[mi]].z+=1147483648;
				}
				if(a[c[mi]].y<0&&a[c[mi]].y>a[c[mi]].z){
					ans=ans-a[c[mi]].z-1147483648;
					a[c[mi]].z+=1147483648;
					a3--;
				}
			}
			for(int i=0;i<n;i++){
				if(a[i].x>=0&&a[i].y>=0&&a[i].z>=0){
					if(a[i].x>a[i].y&&a[i].x>a[i].z&&a1<n/2){
						ans=ans+a[i].x;
					}else if(a[i].y>a[i].x&&a[i].y>a[i].z&&a2<n/2){
						ans=ans+a[i].y;
					}else if(a[i].z>a[i].y&&a[i].z>a[i].x&&a3<n/2){
						ans=ans+a[i].z;
					}
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
