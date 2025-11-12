#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
ll s[maxn];
ll a[maxn];
const int maxm=5e6+10;
ll cnt[maxm];
struct x{
	int l,r;
	bool operator<(const x &o)const{
		return r<o.r;
	}
}x[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	s[0]=0;
	bool flag=0;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(cnt[s[i]]==0)cnt[s[i]]=i;
		if(a[i]!=1)flag=1;
		if(a[i]!=1&&a[i]!=0)f=1;
	}
	if(flag==0){
		if(k==1){
			cout<<n;
		}
		else if(k==0){
			cout<<n/2;
		}
		else cout<<0;
	}
	else if(f==0){
		if(k!=0&&k!=1)cout<<0;
	}
	else{
		int id=0;
		for(int i=1;i<=n;i++){
			int it=s[i]^k;
			if(cnt[it]){
				x[++id].l=cnt[it]+1;
				x[id].r=i;
			}
		}
		sort(x+1,x+id+1);
		int ans=0;
		for(int i=1;i<=id;i++){
			if(x[id].r<x[id+1].l||i==id)ans++;
		}
		cout<<ans;
	}
	
	return 0;
}
