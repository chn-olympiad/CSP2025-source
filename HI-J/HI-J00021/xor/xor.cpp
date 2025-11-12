#include <bits/stdc++.h>
using namespace std;
int n,k;long long a[100086*5], c[5*100086],b[5*100086], ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	int i=1;
	while(i<=n)
	{
		if(b[i-1]!=0)
		{
			c[i]=a[i];
		}
		else if(b[i-1]==0&&k==0)
		{
			c[i]=a[i];
		}
		else
		{
			c[i]=c[i-1]^a[i];
		}
		if(c[i]==k)
		{
			b[i]=c[i];
			ans++;
		}
	//	cout<<c[i]<<endl;
		i++;
		
	}
	cout<<ans;
	return 0;
} 
