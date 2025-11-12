#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
const int N=1e6+5;
int a[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i]))
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}