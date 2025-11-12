#include<bits/stdc++.h>
using namespace std;
#define int long long int
struct node{
	int x,z;
}a[100005],b[100005],c[100005];
struct du{
	int x,y,z;
}num[100005];
bool cmp(node p,node q){
	if(p.x>q.x) return 0;
	else return 1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>num[i].x>>num[i].y>>num[i].z;
		}
		int aber=0,bber=0,cber=0,asum=0,bsum=0,csum=0;
		for(int i=1;i<=n;i++){
			if(num[i].x>=num[i].y&&num[i].x>=num[i].z){
				aber++;
				asum+=num[i].x;
				if(num[i].y>num[i].z){
					a[aber].x=num[i].x-num[i].y;
				}
				else{
					a[aber].x=num[i].x-num[i].z;
				}
				
			}
			else if(num[i].y>=num[i].x&&num[i].y>=num[i].z){
				bber++;bsum+=num[i].y;
				if(num[i].x>num[i].z){
					b[bber].x=num[i].y-num[i].x;
				}
				else{
					b[bber].x=num[i].y-num[i].z;
				}
			}
			else{
				cber++;csum+=num[i].z;
				if(num[i].x>num[i].y){
					c[cber].x=num[i].z-num[i].x;
				}
				else{
					c[cber].x=num[i].z-num[i].y;
				}
			}
		}
		if(aber>n/2){
			sort(a+1,a+1+aber,cmp);
			for(int i=1;i<=aber-n/2;i++){
				asum-=a[i].x;
			}
		}
		else if(bber>n/2){
			sort(b+1,b+1+bber,cmp);
			for(int i=1;i<=bber-n/2;i++){
				bsum-=b[i].x;
			}
		}
		else{
			sort(c+1,c+1+cber,cmp);
			for(int i=1;i<=cber-n/2;i++){
				csum-=c[i].x;
			}
		}
		cout<<asum+bsum+csum<<endl;
	}
	return 0;
}
