#include<bits/stdc++.h>
using namespace std;
int n,cnt1;
long long k,a[500005];
long long b[500005];
struct d{
	int l,r;
}x[500005];
long long mr,ans;
map<long long,int>cnt,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	cnt[0]=0;
	f[0]=1;
	for(int i=1;i<=n;i++){
		if(f[b[i]^k]!=0){
			x[++cnt1].l=cnt[b[i]^k];
			x[cnt1].r=i;
		}
		cnt[b[i]]=i;
		f[b[i]]=1;
	} 
	mr=0;
	ans=0;
	for(int i=1;i<=cnt1;i++){
		if(x[i].l>=mr){
			ans++;
			mr=x[i].r;
		}
	}
	cout<<ans;
	return 0;
}