#include <bits/stdc++.h>
using namespace std;
int f[20];
string s ;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++)if('0'<=s[i]&&s[i]<='9')f[s[i]-'0']++;
	for(int i=9;i>=0;i--)if(f[i])for(int j=1;j<=f[i];j++)cout<<i; 
	return 0;
}
