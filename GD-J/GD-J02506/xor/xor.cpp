#include<bits/stdc++.h>
using namespace std;
long long n,k,a,g[500005][23],l,ans,h[23],maxx;

void er(int now,long long x){
	int ci=0;
	while(x>0){
		ci++,g[now][ci]=x%2;
		x/=2;
	}
	g[now][0]=ci;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	er(0,k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		er(i,a);
		if(a==k){
			ans++,l=i;continue;
		}
		for(int j=1;j<=g[i][0];j++) h[j]=g[i][j];
		for(int j=i-1;j>l;j--){
			bool flat=0;
			g[j][0]=max(g[j][0],g[j+1][0]),g[j+1][0]=g[j][0];
			if(g[j][0]<g[0][0]) break;
			for(int ii=1;ii<=g[j][0];ii++){
				h[ii]+=g[j][ii],g[j][0]=max(g[j][0],g[j+1][0]);
				if(h[ii]%2!=g[0][ii]) flat=1;
			}
			if(!flat){
				ans++,l=i;break;
			}
		}
		for(int j=1;j<=21;j++) h[j]=0;
	}
	cout<<ans;
	return 0;
}
