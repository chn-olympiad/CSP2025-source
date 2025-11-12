#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,k;
int a[maxn];
signed main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(!k){
		cout<<1;
		return 0;
	}
	else if(k==1){
		int qwp=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				qwp++;
			}
		}
		cout<<qwp;
		return 0;
	}
	else{
		
	}
	return 0;
}
