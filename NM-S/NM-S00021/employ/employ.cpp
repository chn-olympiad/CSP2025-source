#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a=rand();
	int n;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		a=i;
		if(i<5000) break;
		      else cout<<a%244<<" "<<a%998<<" "<<a%353;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
