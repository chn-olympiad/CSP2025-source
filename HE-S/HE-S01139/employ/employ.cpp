#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long temp=1,ans=0;
	for(int i=n;i>=1;i--)
	{
		temp*=n;
		ans=temp%998244353;
	}
	cout<<ans<<endl;
	return 0;
}
