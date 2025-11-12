#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a=rand();
	for(int i=1;i<=n;i++)
	{
		a=i;
		if(a<5000) continue;
		      else cout<<a%998<<" "<<a%244<<" "<<a%353;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;	
}
