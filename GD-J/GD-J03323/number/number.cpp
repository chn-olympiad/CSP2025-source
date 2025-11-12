#include<bits/stdc++.h>
using namespace std;
int u[11];
int main()
{
	//#Shang4Shan3Ruo6Shui4
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string sd;
	getline(cin,sd);
	for(int y=0;y<=sd.size();y++)
	{
		int h=sd[y]-0;
		if(h>=48 && h<=57) u[h-48]++;
	}
	for(int q=9;q>=0;q--)
	{
		while(u[q])
		{
			cout<<q;
			u[q]--;
		}
	}
	return 0;
}
