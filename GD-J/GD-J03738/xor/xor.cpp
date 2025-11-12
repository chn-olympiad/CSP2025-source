#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,s1,s2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)s1++;
		else s2++;
	}
	if(m==0&&s1==n)cout<<n/2;
	else 
	{
		if(m==0)cout<<s2+s1/2;
		else cout<<s1;
	}
	return 0;
}
