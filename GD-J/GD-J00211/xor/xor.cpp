#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005];
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((s[i]^s[j])==m){
				ans++;
				i=j;
				break;
			}
		}
	}printf("%lld",ans);
	return 0;
}
