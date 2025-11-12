#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10086;
int n,k,L,cnt,ans,lll,a[N],S[N];
struct rl{
	int l,r;
} T123[N];
bool cmp(rl T12,rl T13){
	return T12.r<T13.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(i == 1){
			S[1] = a[1];
		}
		else{
			S[i] = S[i-1]^a[i];
		}
	}
	cnt = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(i == 1){
				L = S[j];
			}
			else{
				L = S[j]^S[i-1];
			}
			if(L == k){
				cnt++;
				T123[cnt].l = i;
				T123[cnt].r = j;
			}
		}
	}
	sort(T123+1,T123+cnt+1,cmp);
	for(int i = 1;i<=cnt;i++){
		if(i == 1){
			lll = T123[i].r;
			ans = 1;
			continue;
		}
		if(T123[i].l>lll){
			lll = T123[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}