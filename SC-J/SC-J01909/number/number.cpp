#include<bits/stdc++.h>
using namespace std;
string z;
int x[10000000],l;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>z;
	for(int q=0;q<z.size();q++)
	{
		if(z[q]>='0'&&z[q]<='9')
		{
			x[l++]=z[q]-'0';
		}
	}
	sort(x,x+l,cmp);
	if(x[0]==0) cout<<"0";
	else 
	{
		for(int q=0;q<l;q++)
		{
			cout<<x[q];
		}
	}
	return 0;
 } 