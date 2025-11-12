#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,cnt1,cnt2,cnt3,ans=0,minn[maxn];
struct node{
	int a,b,c;
}p[maxn];
bool cmp(node a,node b){
	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		ans=0,cnt1=0,cnt2=0,cnt3=0;
		int flag=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].b>>p[i].c;
		if(n==100000){
			for(int i=1;i<=n/2;i++){
				ans+=p[i].a;
			}
			cout<<ans<<"\n";
		}
		else{
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=n;i++){
				int tot1=max(p[i].a,max(p[i].b,p[i].c));
				ans+=tot1;
				if(tot1==p[i].a) cnt1++;
				else if(tot1==p[i].b) cnt2++;
				else cnt3++;
			}
			int k=n/2;
			for(int i=1;i<=n;i++){
				int tot1=max(p[i].a,max(p[i].b,p[i].c));
				int tot3=min(p[i].a,min(p[i].a,p[i].b));
				int tot2;
				if(tot3==p[i].a) tot2=min(max(tot3,p[i].b),max(tot3,p[i].c));
				if(tot3==p[i].b) tot2=min(max(tot3,p[i].a),max(tot3,p[i].c));
				if(tot3==p[i].c) tot2=min(max(tot3,p[i].b),max(tot3,p[i].a));
				if(cnt1>k||cnt2>k||cnt3>k)
					minn[i]=tot1-tot2;
			}
			sort(minn+1,minn+n+1);
			for(int i=1;i<=k;i++) ans-=minn[i];
			cout<<ans<<"\n";
			}
		}
	return 0;
} 
