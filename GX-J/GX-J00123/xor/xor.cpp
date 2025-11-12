#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],cntA,cntB1,cntB2;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1){cntA++;cntB1++;}
		else if(a[i]==0)cntB2++;
	}
	if(cntA==n&&k==0){cout<<n;return 0;}
	else if(cntB1+cntB2==n&&k<=1)
	{
		if(k==0)cout<<cntB2;	
		else if(k==1)cout<<cntB1;
		return 0;
	}
	
	return 0;
}
