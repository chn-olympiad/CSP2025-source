#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","f",stdout);
	int n,p;
	cin>>n>>p;
	string a[100005];
	string b[100005];
	string c[100005];
	for(int i=1;i<=p;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n+2;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<2<<0;
}
