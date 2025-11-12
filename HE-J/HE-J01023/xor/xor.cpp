#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int n,k,a[maxn],ans=0,dp[maxn];
int power(int a){
	int b=1;
	for(int i=1;i<=a;i++){
		b *= 2;
	}
	return b;
}
int yh(int a,int b){//a = b-1 (?
	if(a == b) return a;
	int num=max(a,b),c = 0,ans = 0;
	while(num != 0){
		num = num/2;
		c++;
	}
	int a1[22],b1[22];
	for(int i = c;i>=1;i--){
		int p = power(i); 
		if(a >= p) {
			a = a%p;
			a1[i] = 1;
		}
		else a1[i] = 0;
		if(b >= p) {
			b = b%p;
			b1[i] = 1;
		}
		else b1[i] = 0;
	}
	for(int i=1;i<=c;i++) if(a1[i] != b1[i]) ans += power(i);
	return ans+1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	for(int l = 1;l<=n;l++){
		for(int r=l;r<=n;r++){
			for(int i=l;i<=r;i++){
				if(yh(a[l],a[i]) == k) ans++;
			}
		}
	}
	cout<<ans;
}
