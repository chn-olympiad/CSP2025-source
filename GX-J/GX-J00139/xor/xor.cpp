
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
int n,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	int k;
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		int ak;
		cin>>ak;
		if(ak==1)
			ans++;
	}
	cout<<ans;
	return 0;	
}

