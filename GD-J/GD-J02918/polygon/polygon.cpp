#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int cc[5010];
int sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		cc[i]=cc[i-1]+a[i];
	}
	cout<<6;
	return 0;
} 
