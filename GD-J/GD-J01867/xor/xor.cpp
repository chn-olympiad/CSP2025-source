#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],l=1,r=1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>a[i],s[i]=(s[i-1]^a[i]);
	if(k==0)
	{
		while(l<=r&&r<=n)
		{   
			if((s[r]^s[l-1])==k)ans++,r++,l=r;
			while((s[r]^s[l-1])>k)r++;
		}
		cout<<ans;
	} 
	else 
	{
		while(l<=r&&r<=n)
		{   
			if((s[r]^s[l-1])==k)ans++,r++,l=r;
			else r++;
			while((s[r]^s[l-1])>k)l++;
		}
		cout<<ans;
	}
	return 0;
} 
