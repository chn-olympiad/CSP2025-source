#include <bits/stdc++.h>
using namespace std;
const int N=5*100000+10;
long long s[N],a[N],mem[N];
long long n,k;
long long L(int x){
	if(mem[x]) return mem[x];
	int res=0,ans=0;
	for(int i=x;i<=n;i++){
		res=res^a[i];
		if(res==k){
			return ans=1+L(i+1);
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=0,tot=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1) cnt++;
		if(a[i]==1 || a[i]==0) tot++;
	}
	if(cnt==n){
		printf("%d",n/2);
		return 0;
	}
	if(tot==n){
		if(k==1) printf("%d\n",cnt);
		else{
			long long i=1,ans=0;
			while(i<=n){
				if(a[i]==0) ans++,i++;
				else if(a[i]==1 && a[i+1]==1) ans++,i+=2;
				else i++;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	long long ansans=0;
	for(int i=1;i<=n;i++){
		ansans=max(ansans,L(i));
	}
	printf("%lld\n",ansans);
	return 0;
}
