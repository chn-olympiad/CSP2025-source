#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int n;
char s[N+5];
int bk[15];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=strlen(s);
	for(int i=0;i<n;i++)
		if(s[i]>='0' && s[i]<='9')
			bk[s[i]-'0']++;
//	for(int i=0;i<=9;i++)
//		cout<<bk[i]<<' ';
	for(int i=9;i>=0;i--)
		for(int j=1;j<=bk[i];j++)
			cout<<i;
	cout<<"\n";
	return 0;
}

