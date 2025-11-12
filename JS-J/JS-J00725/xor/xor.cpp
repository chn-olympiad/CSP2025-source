#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,k;
ll a[N];
ll nowy=0,ans=0;
ll solve(int x,int y){
	if(x==y)return a[x];
	ll cnt=a[x];
	for(int i=x+1;i<=y;i++){
		cnt^=a[i];
	}
	return cnt;
}
struct node{
	int u,v;
};
vector<node> v;
bool cmp(node p,node q){
	return p.v<q.v;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ll tmp=solve(i,j);
			if(tmp==k){
				v.push_back({i,j});
			}
			
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto now:v){
		if(now.u>nowy){
			nowy=now.v;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
