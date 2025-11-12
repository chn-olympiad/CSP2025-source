#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll id,c,num;//id 第几个人 c 第几个社团 
};
ll t,n;
bool cmp(node a,node b){
	return a.num>b.num;
}
node a[300015];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cnt++;
				cin>>a[cnt].num;
				a[cnt].c=j;
				a[cnt].id=i;
			}
		}
		sort(a+1,a+cnt+1,cmp);
		bool vis[300005]={false};
		vector<ll> g1;
		vector<ll> g2;
		vector<ll> g3;
		for(int i=1;i<=cnt;++i){
			if(a[i].c==1&&g1.size()<n/2&&vis[a[i].id]==false){
				g1.push_back(a[i].num);
				vis[a[i].id]=true;
			}
			else if(a[i].c==2&&g2.size()<n/2&&vis[a[i].id]==false){
				g2.push_back(a[i].num);
				vis[a[i].id]=true;
			}
			else if(a[i].c==3&&g3.size()<n/2&&vis[a[i].id]==false){
				g3.push_back(a[i].num);
				vis[a[i].id]=true;
			}
		}
		ll ans=0;
		for(ll v:g1){
			ans+=v;
		}
		for(ll v:g2){
			ans+=v;
		}
		for(ll v:g3){
			ans+=v;
		}
		cout<<ans<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
