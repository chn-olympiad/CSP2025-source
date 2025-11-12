#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,i,j,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>j;
		if(j==1){
			ans+=1;
		}
	}
	if(ans==n){
		cout<<n;
		return 0;
	}
	cout<<max(ans,n-ans);
	return 0;
}