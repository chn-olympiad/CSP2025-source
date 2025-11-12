#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;int ma=0;int sum;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		if(a[i]>ma)
		{
			ma=a[i];
		}
	}
	
	
} 
