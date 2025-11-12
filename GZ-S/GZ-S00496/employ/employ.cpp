//GZ-S00496 贵阳市第三中学 马俊杰 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=505;
const int p=998244353;
int n,m;
string s;
int c[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int res=1;
	for(int i=2;i<=n;i++)
	{
		res*=i;
		res%=p;
	}
	cout<<res<<'\n';
	return 0;
}
