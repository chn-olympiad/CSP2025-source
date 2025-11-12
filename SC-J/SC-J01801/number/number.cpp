#include<bits/stdc++.h>
using namespace std;
#define L long long
#define S string
#define B bool
#define C char
S no_letters(S in,L _size)
{
	S ans="";
	for(L i0=0;i0<_size;i0++)
	{
		if(in[i0]>='0'&&in[i0]<='9')
		{
			ans+=in[i0];
		}
	}
	return ans;
}
B cmp(C a,C b)
{
	return a>b;
}
signed main()
{
	//唯一识别码：deqvudedqhsqbhsabhsvhqdgvdwgvygy
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	S in;
	cin>>in;
	in=no_letters(in,in.size());
	sort(in.begin(),in.end(),cmp);
	cout<<in;
	return 0;
}