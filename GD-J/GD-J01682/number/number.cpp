#include<bits/stdc++.h>
using namespace std;
#define int long long
string a;
map<int,int>mp;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		mp[a[i]]++;
	}
	for(int i=9;i>=0;i--){
		while(mp[i+48]){
			mp[i+48]--;
			cout<<i;
		}
	}
	return 0;
}
