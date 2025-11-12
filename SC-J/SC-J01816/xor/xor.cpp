#include<bits/stdc++.h>  
using namespace std;
const int N=5e5+11;
int n,k,a[N],ans;
long long s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	s[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
	}
	int l=1;
	while(l<=n){
		int r=l;
		while(r<=n){
			if((s[r]^s[l-1])==k){
				l=r;
				ans++;
				break;
			}
			r++;
		}
		l++;
	}
	printf("%d",ans);
	return 0;
}
