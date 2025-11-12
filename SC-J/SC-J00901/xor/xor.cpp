#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
#define ll long long
int n,k,g[N],sum[N],ans;
void fz(int l,int r,int len){
	if(len>n||l>r)return;
	for(int i=l+len-1;i<=r;i++){
		if((sum[i]^sum[i-len])==k){
			ans++;
			fz(l,i-len,len+1),fz(i+1,r,len);
			return;
		}
	}
	fz(l,r,len+1);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){cin>>g[i];sum[i]=sum[i-1]^g[i];}
	fz(1,n,1);
	cout<<ans;
	return 0;
}