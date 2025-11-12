#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7;
ll n,m,ans,cnt,lst=-1,a[maxn],s[maxn];
struct node{
	ll s,e;
}b[maxn];
bool cmp(node x,node y){
	if(x.e==y.e){
		return x.s<y.s;
	}
	return x.e<y.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if((s[i-1]^s[j])==m){
				b[++cnt].s=i;
				b[cnt].e=j;
				break;
			}
		}
	}
	sort(b+1,b+1+cnt,cmp);
	for(ll i=1;i<=cnt;i++){
		if(b[i].s>lst){
			ans++;
			lst=b[i].e;
		}
	}
	cout<<ans<<endl;
	return 0;
}
