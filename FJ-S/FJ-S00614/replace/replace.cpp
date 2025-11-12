#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,t;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	srand(time(0));
	for (int i=0;i<q;i++)
	{
		t=abs(rand()*rand()*rand())%100;
		if (t<90) cout<<"0\n";
		else if (t<99) cout<<t%10<<'\n';
		else cout<<(t*rand())%15<<'\n';
	}
	return 0;
}

