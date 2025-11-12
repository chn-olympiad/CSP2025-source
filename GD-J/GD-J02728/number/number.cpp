#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string x;
    cin>>x;
    int a[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<x.size();i++)
	{
		int z=x[i]-'0';
		if(z>=0 && z<=9)
		{
			a[z]++;
		}
	 } 
	for(int i=9;i>=0;i--)
	{
		if(a[i]==0) continue;
		for(int j=1;j<=a[i];j++)
		{
			cout<<i; 
		}
	}
    return 0;
}
