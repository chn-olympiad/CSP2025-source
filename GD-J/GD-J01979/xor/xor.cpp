#include <bits/stdc++.h>
using namespace std;
int n,k,x,y,cnt;
map<int,bool>m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	x=0;
	m[0]=true;
	for(int i=1;i<=n;++i)
	{
		cin>>y;
		x=x^y;
		if(m[x^k])
		{
			cnt++;
			m.clear();
		}
		m[x]=true;
	}
	cout<<cnt<<"\n";
	return 0;
}
