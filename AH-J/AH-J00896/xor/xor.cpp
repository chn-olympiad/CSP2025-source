#include<bits/stdc++.h>
using namespace std;

int n, k, cnt;
int a[200005];
int zone[200005];

int xo(int p, int q)
{
	if(p==q)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	int res; //res储存结果
	for(int l=1;l<=n;l++)
	{
		res = a[l];
		int r=l;
		while(res!=k && r<=n)
		{
			r++;
			res = xo(res,a[r]);
		}
		if(res==k){
		zone[l]=r;}
	}
	int l=1;
	while(l)
	{
		if(l!=0){
			l=zone[l]+1;
			cnt++;}
		else{
			break;}
	} 
	cout<<cnt;                                                                                                                 ;
	return 0;
}




