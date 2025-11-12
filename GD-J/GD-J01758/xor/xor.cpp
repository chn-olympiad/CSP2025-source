#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=5e5+5;
int n,k,a[M],s[M],t[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<N;i++) t[i]=-1;t[0]=0;
	for(int i=1,r=0;i<=n;i++){
		if(r<=t[s[i]^k]) r=i,ans++;
		t[s[i]]=i;
	}cout<<ans;
	return 0;
}
