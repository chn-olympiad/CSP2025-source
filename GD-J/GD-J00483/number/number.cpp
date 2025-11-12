#include <bits/stdc++.h>
using namespace std;
int n,m,k,f[1145145];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) f[s[i]-'0']++;
	for(int i=9;i>=0;i--) while(f[i]) cout<<i,f[i]--;
}
