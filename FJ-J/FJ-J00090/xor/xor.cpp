#include<bits/stdc++.h>
using namespace std;
int n,k,a[500100];
int  yihuo(int a,int b)
{
	int ans=0;
	while(a!=0||b!=0)
	{
		int aa=a%2,bb=b%2;
		a/=2,b/=2;
		cout<<aa<<" "<<bb<<endl;
		if(aa==1||bb==1) ans+=1;
	}
	return ans;
} 
 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)ans++;
	}
	if(ans==0)cout<<n/2;
	else
	    cout<<ans;
	return 0;
}
