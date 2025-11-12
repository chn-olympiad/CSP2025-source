#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+6;
int t;
int n;
struct node{
	int a1,a2,a3;
	int fi,id,mi,kk,se;
}a[maxn];
int k5[maxn];
bool cmp1(node a,node b){
	if(a.kk==b.kk) return a.fi>b.fi;
	return a.kk>b.kk;
}
int vis[maxn];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		int s1=0,s2=0,s3=0,tot=0;
		int ss=0;
		int m=n/2; 
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3; 
			a[i].fi=max(a[i].a1,max(a[i].a2,a[i].a3));
			a[i].id=(a[i].fi==a[i].a1?1:(a[i].fi==a[i].a2?2:3));
			a[i].mi=min(a[i].a1,min(a[i].a2,a[i].a3));
			if(a[i].id==1){
				a[i].se=max(a[i].a2,a[i].a3);
			}
			if(a[i].id==2){
				a[i].se=max(a[i].a1,a[i].a3);
			}
			if(a[i].id==3){
				a[i].se=max(a[i].a2,a[i].a1);
			}
			a[i].kk=a[i].fi-a[i].se;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].id==1){
				if(s1+1<=m){
					s1++;
					ans+=a[i].fi;
					vis[i]=1;
				}else{
					a[i].a1=-1e9;
					ss=1;
					break;
				}
			}
			if(a[i].id==2){
				if(s2+1<=m){
					s2++;
					ans+=a[i].fi;
					vis[i]=1;
				}else{
					ss=2;
					a[i].a2=-1e9;
					break;
				}
			}
			if(a[i].id==3){
				if(s3+1<=m){
					s3++;
					ans+=a[i].fi;
					vis[i]=1;
				}else{
					ss=3;
					a[i].a3=-1e9;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				if(a[i].id==1&&a[i].id==ss){
					a[i].a1=-1e9;
				}
				if(a[i].id==2&&a[i].id==ss){
					a[i].a2=-1e9;
				}
				if(a[i].id==3&&a[i].id==ss){
					a[i].a3=-1e9;
				}
				k5[++tot]=max(a[i].a1,max(a[i].a2,a[i].a3));
			}
		}
		for(int i=1;i<=tot;i++){
			ans+=k5[i];
		} 
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
	}
	return 0;
}

