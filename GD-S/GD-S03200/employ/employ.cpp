#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int n,m,c[100010];
ll ans;
bool dif[100010];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	bool px=1;
	for(int i=1;i<=n;i++)
	{
		cin>>dif[i];
		if(!dif[i]) px=0;
	}
	if(px){
		ll s=1;
		for(int i=1;i<=n;i++)
		{
			s=(s*i)%M;
		}
		cout<<s<<"\n";
	}
	else{
		cout<<"0\n";
	}
	return 0;
 } 
