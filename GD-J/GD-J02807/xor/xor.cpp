#include<bits/stdc++.h>
using namespace std;
struct kk{
	int start;
	int end;
}; 
bool cmp(kk a,kk b)
{
	return a.end<b.end;
}
int main()
{
	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[1050];
	int f[1005][1005];
	int kknum=0;
	kk ds[10000005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i]=a[i];
		if(a[i]==k) 
		{
			kknum++;
			ds[kknum].start=i;
			ds[kknum].end=i;
		}
	 } 
	
	
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			f[i][j]=(f[i][j-1]^a[j]);
			if(f[i][j]==k)
			{
				kknum++;
				ds[kknum].start=i;
				ds[kknum].end=j;
			}
		}
	}
	sort(ds+1,ds+kknum+1,cmp);
	//cout<<f[1][1]<<f[2][4];
	//cout<<kknum;
	int endnow=0;
	int sum=0;
	for(int i=1;i<=kknum;i++)
	{
		if(ds[i].start>endnow)
		{
			sum++;
			endnow=ds[i].end;
		}
	}
	cout<<sum;
	return 0;
 } 
