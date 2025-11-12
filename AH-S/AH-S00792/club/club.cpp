#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,d;
}g[100005],r[100005],l[100005];
bool cmp(node x,node y){
	return x.a<y.a;
}
bool cmp2(node x,node y){
	return x.d<y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		bool f2=1,f3=1;
		for(int i=1;i<=n;i++){
			cin>>g[i].a>>g[i].b>>g[i].c;
			if(g[i].c!=0){
				f3=0;
			}
			if(g[i].b!=0){
				f2=0;
			}
		}
		if(f3&&f2){
			sort(g+1,g+1+n,cmp);
			int ans=0;
			for(int i=n;i>=n-n/2+1;i--){
				ans+=g[i].a;
			}
			cout<<ans<<'\n';
		}
		else if(f3){
			int cnt1=0,cnt2=0,ans=0;
			for(int i=1;i<=n;i++){
				if(g[i].a>=g[i].b){
					cnt1++;
					ans+=g[i].a;
					l[i]=g[i];
					g[i].d=g[i].a-g[i].b;
				}
				else{
					cnt2++;
					ans+=g[i].b;
					r[i]=g[i];
					g[i].d=g[i].b-g[i].a;
				}
			}
			if(cnt1==cnt2){
				cout<<ans<<'\n';
			}
			else{
				int k=abs(cnt1-cnt2);
				if(cnt1>cnt2){
					sort(l+1,l+1+n,cmp2);
					for(int i=1;i<=k/2;i++){
						ans-=l[i].d;
					}
				}
				else{
					sort(r+1,r+1+n,cmp2);
					for(int i=1;i<=k/2;i++){
						ans-=r[i].d;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
