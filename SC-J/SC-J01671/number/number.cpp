#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++)if(int(s[i])>=48&&int(s[i])<=57)a[int(s[i])]++;
	for(long long i=57;i>=48;i--)for(long long j=1;j<=a[i];j++)cout<<i-48; 
	return 0;
}