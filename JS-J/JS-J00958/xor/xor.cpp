#include<bits/stdc++.h>
using namespace std;
long long n,k,x1[500009],ans=0,x2[500009][25],w=0,w1,ann=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&x1[i]);
		if(x1[i]==k){
			ans++;
			x1[i]=-1;
		}
	}
	for(int i=0;i<=n+1;i++)for(int j=1;j<=22;j++)x2[i][j]=0;
	x1[n+1]=k;
	for(long long i=1;i<=n;i++){
		if(x1[i]!=-1){
			long long q=x1[i],an=1;
			while(q>0){
				ann=max(an,ann);
				if(q%2==1)x2[i][an]=1;
				q/=2,an++;
			}
			for(int j=1;j<=22;j++)x2[i][j]+=x2[i-1][j];
		}
	}

	long long q=x1[n+1],an=1;
	while(q>0){
		ann=max(an,ann);
		if(q%2==1)x2[n+1][an]=1;
		q/=2,an++;
	}
	for(long long i=1;i<=n;i++){
		w1=w;
		if(x1[i]!=-1){
			while(w1<i){
				long long po=1;
				for(long long j=1;j<=ann;j++){
					if((x2[i][j]-x2[w1][j])%2!=x2[n+1][j]){
						po=0;
					}
				}
				if(po==1){
					ans++,w=i;
					break;
				}
				w1++;
			}
		}else w=i;
	}
	printf("%lld",ans);
	return 0;
}
