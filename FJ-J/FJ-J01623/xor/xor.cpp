#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k,a[N],ans[N],shu;
int check(int l,int r){
	int x=ans[r]^ans[l-1];
	if(x==k) return 1;
	else return 0;
}
int abc(int l,int r){
	if(l==r) 
	{
		return check(l,r);
	}
	int maxn=0;
	for(int i=l;i<r;i++)
	{
		maxn=max(maxn,abc(l,i)+abc(i+1,r));
		if(maxn==n||maxn==shu) return maxn;
	}
	return max(check(l,r),maxn);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	shu=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[i]=a[i]^ans[i];
		if(a[i]==0) shu--;
	}
	bool f=1;
	if(k==0)
		for(int i=2;i<=n;i++) 
			if(a[i]!=a[i-1]&&a[i]!=0&&a[i-1]!=0) f=0;
	if(f==1)
	{
		cout<<shu;
		return 0;
	} 
	f=1;
	int sum=n;
	for(int i=1;i<=n;i++) 
	{
		if(a[i]!=k)
		{
			if(a[i]==0) sum--;
			else
			{
				f=0;
				break;
			}
		}
	}
	if(f==1) 
	{
		cout<<sum;
		return 0;
	}
	cout<<abc(1,n);
	return 0;
}
