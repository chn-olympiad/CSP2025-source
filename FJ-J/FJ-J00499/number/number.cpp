#include<bits/stdc++.h>
using namespace std;
string s;
long long a[20];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n = s.size();
	for(long long i = 0; i<n; i++)if(s[i]<='9'&&s[i]>='0')a[s[i]-'0']++;
	for(long long i = 9; i>=0; i--)for(long long j = 1; j<=a[i]; j++)cout<<i;
	cout<<"\n";
	return 0;
}
