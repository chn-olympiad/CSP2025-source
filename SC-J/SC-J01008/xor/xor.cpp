#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k,a[N],fl=1,f[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) fl=0;
	}
	if(fl){
		int ans=0;
		for(int i=2;i<=n;i+=2){
			ans+=(n-i+1);
		} 
		printf("%lld",ans);
	}
	else{
		fl=0;
		if(a[1]==k) f[1]=1;
		for(int i=1;i<=n;i++){
			f[i]=INT_MIN;
			for(int j=i;j>=1;j--){
				int x=a[j];
				for(int s=j+1;s<=i;s++){
					x^=a[s];
				}
				if(x==k){
					f[i]=max(f[i],f[j-1]+1);
				}
			} 
		}
		int mx=INT_MIN;
		for(int i=n;i>=1;i--){
			if(f[i]){
				fl=1;
				mx=max(mx,f[i]);
			}
		}
		if(!fl) printf("0");
		else printf("%lld ",mx);
	}
	return 0;
}