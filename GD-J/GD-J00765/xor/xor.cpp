# include<bits/stdc++.h>
using namespace std;
int qzmx[500005],dp,ZY[1<<20],n,k,ipt,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(ZY,-1,sizeof(ZY));
	ZY[0]=sum=0;
	for(int i = 1;i<=n;i++){
		cin>>ipt,sum^=ipt;
		qzmx[i]=qzmx[i-1];
		if(ZY[sum^k]>=0)qzmx[i]=max(qzmx[i],qzmx[ZY[sum^k]]+1);
		ZY[sum]=i;
	}
	cout<<qzmx[n];
	return 0;
}
