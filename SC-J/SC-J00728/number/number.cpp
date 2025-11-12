#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10],f=0;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=s.length()-1;i>=0;i--){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}