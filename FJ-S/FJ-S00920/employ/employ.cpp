#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[100000],val=1;
	char zf;
	cin>>n>>m>>zf;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		val*=i;
	}
	val = val%998244353;
	cout<<val;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
