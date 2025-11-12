#include<bits/stdc++.h>
using namespace std;
int a[5000000],n,k,tot=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==k&&a[j]!=0&&j!=i)
				tot++;
		}
	}
	cout<<tot;
	return 0;
}