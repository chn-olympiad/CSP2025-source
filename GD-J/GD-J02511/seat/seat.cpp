#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int p=1;
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])p++;
	}
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		sum+=n;
		if(p<=sum){
			cout<<i<<" ";
			if(i%2){
				cout<<p-sum+n;
				break;
			}
			else{
				cout<<sum-p+1;
				break;
			}
		}
	}
	return 0;
}

