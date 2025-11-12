#include<bits/stdc++.h>
#define ff(i,n) for(int i=1;i<=n;i++) 
#define int long long
using namespace std;
const int N=5e5+10,M=3e6,mod=993644353; 
int i,j,k,n,m,x,y,tot;
int ma[N],sum[N],pos[M];
main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ff(i,n){
		cin>>x;
		sum[i]=sum[i-1]^x;
	}
	memset(pos,-1,sizeof pos);
	pos[0]=0;
	ff(i,n){
		int res=0;
		if(pos[sum[i]^k]!=-1)res=ma[pos[sum[i]^k]]+1;
		pos[sum[i]]=i;
		ma[i]=max(ma[i-1],res);
//		cout<<ma[i]<<' ';
	}
	cout<<ma[n];
}
