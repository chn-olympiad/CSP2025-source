#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1000005
ll b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string a;
	cin>>a;
	int cnt = 1;
	ll l = a.size();
	for(ll i = 0;i<l;i++){
		if(a[i] >= '0' && a[i] <= '9'){
			b[cnt] = a[i]-'0';
			++cnt;
		}
	}
	sort(b,b+cnt);
	for(ll i = cnt-1;i>0;i--)cout<<b[i];
	return 0;
	
}