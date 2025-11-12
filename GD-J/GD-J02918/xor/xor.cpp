#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum=0;
int a[500005];
int cc[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cc[i]=(cc[i-1]^a[i]); 
	}
	int l=1;
	int r=1;
	while(l<=n)
	{
		if((cc[r]^cc[l-1])==k)
		{
			sum++;
			l=r+1;
			r=l;
		}
		else
		{
			if(r==n)
			{
				l++;
				r=l;
			}
			else
			{
				r++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
