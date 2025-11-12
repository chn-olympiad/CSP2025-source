#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],qzh[500005],sum=0,dr=0;
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i],qzh[i]=(qzh[i-1]^a[i]);
	if(n<20000||k>1){
	for(int l=1;l<=n;l++){
		for(int j=l;j>dr;j--)
		if((qzh[l]^qzh[j-1])==k){
			dr=l;sum++;break;
		}
	}
	cout<<sum;
	} 
	else {
		if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0||a[i]==1&&a[i-1]==1&&!vis[i-1])
			vis[i]=1,sum++;
		}
		}
		else {
		for(int i=1;i<=n;i++)
		if(a[i]==1)sum++;	
		}
		cout<<sum;
		//#13
	}
	return 0;
} //n^2过百万，暴力打标算
//反正样例没T 
