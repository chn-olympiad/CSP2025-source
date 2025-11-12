#include<bits/stdc++.h> 
using namespace std;
int n,k,a[100000005],ans=0,flag[100000005],tmp[100000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    
	cin>>n>>k;
	memset(flag,0,sizeof(flag));
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
			flag[i]=1;
		}
		else
		{
			tmp[i]=a[i];
		}
	}
	cout<<ans;
	return 0;
}
