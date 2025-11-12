#include<bits/stdc++.h>
//9:35
using namespace std;
const int N=501939;
int qzh[N],n,k,a[N],yssans;
void zhao(int l,int r,int yssd){
	if(l>r)return;
	if(l==r){
		if(a[l]==k){
			yssans++;
		}
		return;
	}
	int maxl=r-l+1;
	for(int yss=yssd;yss<=maxl;yss++){
		for(int i=l;i<=r-yss+1;i++){
			if((qzh[i-1]^qzh[i+yss-1])==k){
				yssans++;
				zhao(l,i-1,yss+1);
				//cout<<i<<' '<<i+yss-1<<'\n';
				zhao(i+yss,r,yss);
				return;
			}
		}
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		qzh[i]=qzh[i-1]^a[i];
	}
	/*
	for(int yss=1;yss<=n;yss++){
		for(int i=1;i<=n-yss+1;i++){
			if((qzh[i-1]^qzh[i+yss-1])==k){
				yssans++;
				
			}
		}
	}
	*/
	zhao(1,n,1);
	cout<<yssans;
	return 0;
}
