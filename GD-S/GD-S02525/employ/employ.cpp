#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=501;
ll n,m;
string s;
ll a[N];
ll sum;
int main()
{
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]=='1') sum++;
	}
	if(sum>=n) cout<<m;
	else cout<<sum;
	fclose(stdin);
	fclose(stdout);
}
