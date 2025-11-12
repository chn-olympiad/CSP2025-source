#include<iostream>
#include<cstdio>
using namespace std;
int shuzi[15];
string zfc;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>zfc;
	int i=0;
	while(i<zfc.size())
	{       
		if(zfc[i]>='0'&&zfc[i]<='9')
			shuzi[zfc[i]-'0']++;
		i++;
	}
	for(int k=9;k>=0;k--)
		for(int j=1;j<=shuzi[k];j++)
			cout<<k;
	return 0;
}