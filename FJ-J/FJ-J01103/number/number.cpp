#include<bits/stdc++.h>
using namespace std;
string szifuchuan;
int ashuzu[1000010],n;
int main()
{ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>szifuchuan;
	n=szifuchuan.size();
	for(int i=0;i<=n;i++)
	{
		if(szifuchuan[i]>='0'&&szifuchuan[i]<='9')
		{
			ashuzu[i]=int(szifuchuan[i])-48;
		}
		else
		{
			ashuzu[i]=-1;
		}
	}
	sort(ashuzu+0,ashuzu+0+n);
	for(int i=n;i>=0;i--)
	{
		if(ashuzu[i]!=-1)
		{
			cout<<ashuzu[i];
		}
	}
	return 0; 
} 
