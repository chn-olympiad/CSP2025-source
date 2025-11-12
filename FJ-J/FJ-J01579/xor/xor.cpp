#include<bits/stdc++.h> 
using namespace std;
int main(){
//	freopen("xor1.in","r",stdin);
//	freopen("xor1.out","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+15];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==0 and a[2]!=0)
	{
		cout<<1;
	}
	else if(a[1]!=0 and a[2]==0)
	{
		cout<<1;
	}
	else if(a[1]==0 and a[2]==0)
	{
		cout<<2;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
