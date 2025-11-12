#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
iont a[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,k;
	string q;
	cin>>n>>k>>q;
	long long sum=1;
	int nw=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		nw++;
	}
	for(int i=1;i<=nw;i++)
	{
		sum*=i;
		sum%=p;
	}
	if(nw<m)
	{
		cout<<0;
	}
	else
	{
		cout<<sum;
	}
	return 0;
} 
