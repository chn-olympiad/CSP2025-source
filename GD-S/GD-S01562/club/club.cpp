#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll T;
struct jj{
	ll x,y,z;
}a[N];
ll n;
ll dfs(ll i,ll sum,ll cx,ll cy,ll cz){
	if(cx>n/2||cy>n/2||cz>n/2)return 0;
	if(i>n)return sum;
	ll maxx=-1;
	ll k=i+1;
	ll num;
	for(ll j=0;j<3;j++){
		if(j==0&&cx<n/2){
			cx++;
			num=sum+a[i].x;
			maxx=max(maxx,dfs(k,num,cx,cy,cz));	
			cx--;
		}else if(j==1&&cy<n/2){
			cy++;
			num=sum+a[i].y;
			maxx=max(maxx,dfs(k,num,cx,cy,cz));
			cy--;
		}
		else{
			cz++;
			num=sum+a[i].z;
			maxx=max(maxx,dfs(k,num,cx,cy,cz));
			cz--;
		} 
	}
	return maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ll sum=0;
		for(ll i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		cout<<dfs(1,0,0,0,0)<<endl;
	}
	
	return 0;
} 
