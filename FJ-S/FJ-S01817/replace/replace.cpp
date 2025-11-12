#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=0;
string a1[200005],a2[200005],t1,t2;
bool pd(ll x,ll y){
//	cout<<a1[y]<<" "<<a2[y]<<" "<<x<<" "<<y<<endl;
	for(int i = 0;i < t1.length();i ++){
//		cout<<i<<" "<<t2[i]<<" "<<a2[y][i-x]<<" "<<t1[i]<<" "<<a1[y][i-x]<<" "<<t2[i]<<" "<<t1[i]<<endl;
		if(i >= x and i < x + a1[y].length()){
			if(t2[i]!=a2[y][i-x] or t1[i] != a1[y][i-x]){
				return false;
			}
		}else
		{
			if(t2[i] != t1[i]){
				return false;
			}
		}
	}return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,q;
	cin>>n>>q;
	for(ll i = 1;i <= q;i ++){
		cin>>t1>>t2;
		ans=0;
		for(ll x = 0;x < t1.length();x ++){
			for(ll y = 1;y <= n;y ++){
				if(pd(x,y)){
					ans++;
				}
			}
		}cout<<ans<<endl;
	}
	
	return 0;
} 
