#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	ll n,k,ans=0,flag=0;
	cin>>n>>k;
	vector<ll>v;
	v.clear();
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(v.size()>0){
			for(int j=0;j<v.size();j++){
				v[j]=v[j]^a[i];
				if(v[j]==k){
					flag=1;
					break;
				}
			}
		}
		v.push_back(a[i]);
		if(v[v.size()-1]==k)flag=1;
		if(flag){
			ans++;
			v.clear();
			flag=0;
		}
	}
	cout<<ans;
	return 0;
} 
