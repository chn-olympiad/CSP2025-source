#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,s[500010],ss[500010],cnt,ans;
struct sc{
	int l,r;
}t[500010];
bool cmp(sc c1,sc c2){
	return c1.r<c2.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		int c=ss[i-1]^s[i];
		ss[i]=c;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int c=ss[i]^ss[j];
			if(c==k){
				t[++cnt].l=i+1;
				t[cnt].r=j;
				break;
			}
		}
	}
	sort(t+1,t+1+cnt,cmp);
	int m=0,cntt=1;
	while(m<=n){
		if(m<t[cntt].l){
			m=t[cntt].r;
			ans++;
		}
		cntt++;
		if(cntt>cnt){
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
