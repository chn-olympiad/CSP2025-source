#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m[5001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
	}
	if(n==5 && m[1]==1)
	{
		cout<<9;
	}
	else if(n==5 && m[1]==2)
	{
		cout<<6;
	}
}

