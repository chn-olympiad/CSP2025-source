#include<bits/stdc++.h>
using namespace std;
    int a,b,c,i,j=-1,g[1000001];
	string x,y;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	getline(cin,x);
	for(i=0;i<x.size();i++)
	{
		if(x[i]<='9'&&x[i]>='0')
		{
			j++;
			g[j]=x[i]-'0';
		}
	}
	sort(g,g+j);
	for(i=j;i>=0;i--)
	cout<<g[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
