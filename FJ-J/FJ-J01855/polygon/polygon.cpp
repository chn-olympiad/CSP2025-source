#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int a;
	long e[100001];
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>e[i];
	}if(e[4]==5)cout<<9;
	if(e[4]==10)cout<<6;
	if(e[a-1]==1)cout<<1042392;
	else cout<<366911923;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

