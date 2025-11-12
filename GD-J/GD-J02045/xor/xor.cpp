#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,b[500005],num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i])b[++num]=a[i];
	}
	if(k==0)
	{
		cout<<(int)num/2;
	}
	if(k==1)
	{
		cout<<num;
	}
	return 0;
}
