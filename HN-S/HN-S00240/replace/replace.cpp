#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,sum=0;
	cin>>n>>q;
	int s[n+1][3],t[q+1][3];
	for(int i=1;i<=n;i++)
	{
		for(int l=1;i<=;i++)
		{
			cin>>s[i][l];
		}
	}
	for(int j=1;j<=q;i++)
	{
		for(int l=1;i<=;i++)
		{
			cin>>t[j][l];
		}
	}
	for(int l=1;i<=;i++)
	{
		if(s[n][l]==t[q][l])sum++;	
	}
		cout<<sum<<endl;
	return 0;
}
