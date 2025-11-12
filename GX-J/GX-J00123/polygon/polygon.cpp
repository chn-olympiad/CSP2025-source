#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,num[N],maxx3,sum3;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){cout<<0;return 0;}
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];maxx3=max(maxx3,num[i]);sum3+=num[i];
	}
	if(n==3)
	{
		if(sum3>maxx3*2)cout<<1;
		else cout<<0;
		return 0;
	}	
	return 0;
}

