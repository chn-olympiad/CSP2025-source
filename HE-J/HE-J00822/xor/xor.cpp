#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int p[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0&&p[i+1]==0)
		{
			cout<<2;
		}
		else if(p[i]=p[i+1]) cout<<1;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
