#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[5005],num[5005],kind[5005],ans;
//struct node{
//	int lt,rt,mx,sum;
//}tr[4*5005];
//void build(int add,int l,int r)
//{
//	if(l<r)
//	{
//		build(add*2,l,(l+r)/2);
//		build(add*2+1,(l+r)/2+1,r);
//	}
//	tr[add].lt=l,tr[add].rt=r;
//	tr[add].sum=tr[add*2].sum+tr[add*2+1].sum;
//	tr[add].mx=max(tr[add*2].mx,tr[add*2+1].mx);
//	return;
//}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num[a[i]]++;
		if(num[a[i]]==1)kind[0]++,kind[kind[0]]=a[i];
	}
	sort(kind+1,kind+kind[0]+1);
	for(int i=1;i<kind[0]-1;i++)
	{
		for(int j=i+1;j<=kind[0]-1;j++)
		{
			int p=kind[i]+kind[j];
			for(int k=j+1;k<=kind[0]&&k<=p/2;k++)
			{
				int q=num[kind[i]]*num[kind[j]]%M;
				ans=(ans+q*num[kind[k]]%M)%M;
			}
		}
	}
	return 0;
}
