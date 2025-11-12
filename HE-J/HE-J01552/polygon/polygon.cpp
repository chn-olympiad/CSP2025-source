#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int nnn;
	cin>>nnn;
	if(nnn<3)
	{
		cout<<0;
	}
	else if(nnn=3)
	{
		cout<<1;
	}
	else{
		cout<<nnn*nnn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
