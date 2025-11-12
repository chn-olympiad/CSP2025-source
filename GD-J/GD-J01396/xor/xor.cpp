#include<bits/stdc++.h>
using namespace std;

int n,k,a[500010],sum[500010],pre[1100010],lst,cnt,m,x; 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(pre,0x3f,sizeof(pre));
	pre[0]=0;
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		m=k^sum[i],x=pre[m];
		if(x>=lst&&x!=0x3f3f3f3f) cnt++,lst=i;
		pre[sum[i]]=i;
	} cout<<cnt<<'\n';
	return 0;
}

