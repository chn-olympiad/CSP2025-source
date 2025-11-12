#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N],b[N],ans,sum;
int ban[N],banx;
int lsx;
struct area
{
	int left,right;
}ls[N];
bool cmp(area xx,area yy)
{
	if(xx.left==yy.left)
		return xx.right<yy.right;
	return xx.left<yy.left;
}
int solve2(int l,int r)
{
	if(l==r)
		return 0;
	int summ=0;
	for(int i=1;i<=lsx;i++)
		if(ls[i].left>l&&ls[i].right<r)
			summ=max(solve2(ls[i].left,ls[i].right)+1,summ);
	return summ;
}
int solve(int x,int y)
{
	sum=0,lsx=0;
	/*int dp[N];
	memset(dp,127,sizeof(dp));*/
	for(int i=x+1;i<y;i++)
		for(int j=i;j<y;j++)
			if((b[j] xor b[i-1])==k)
				lsx++,ls[lsx].left=i,ls[lsx].right=j;
	
	/*
	if(lsx)
		for(int i=1;i<=lsx;i++)
			cout<<lsa[i]<<" "<<lsb[i]<<"\n";
	*/
	sort(ls+1,ls+1+lsx,cmp);
	//cout<<lsx<<"\n";
	
	sum=lsx;
	
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=b[i-1] xor a[i];
	
	ban[0]=0;
	for(int i=1;i<=n;i++)
		if(a[i]==k)
			ban[++banx]=i;
	ban[banx+1]=n+1;
	ans=banx;
	for(int i=0;i<=banx;i++)
		ans+=solve(ban[i],ban[i+1]);
	//cout<<ban[banx+1]<<"\n";
	cout<<ans;
	return 0;
}
