#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500010],q[500010];
int l,r,rr,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	q[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		q[i]=a[i]^q[i-1];
	}
	l=0,r=1;
	while(r<=n){
		if((q[r]^q[l])==k){
			l=r;
			r++;
			ans++;	
		}
		else{
			r++;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
