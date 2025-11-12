#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[501010];
long long ans;
struct rec{
	int l,r;
}v[501010];
bool cmp(rec g,rec h){
	if(g.l==h.l)return g.r<h.r;
	return g.l<h.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	int cnt1=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1)cnt++;
		else if(a[i]==0)cnt1++;
	}
	if(cnt==n&&k==0){
		cout<<n/2;
	}
	else if(cnt1+cnt==n&&k<=1){
		if(k==0){
			int cou=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)cou++;
				else {
					ans+=(cou/2);
					cou=0;
				}
			}
			ans+=(cou/2);
			cout<<ans+cnt1;
		}
		else cout<<cnt;
	}
	else{
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				v[++cnt].l=v[cnt].r=i;
			}
			long long g=a[i];
				for(int j=i+1;j<=n;j++){
					g^=a[j];
					if(g==k){
					v[++cnt].l=i,v[cnt].r=j;
				}
			}
		}
		sort(v+1,v+cnt+1,cmp);
		int R=v[1].r;
		ans=1;
		for(int i=2;i<=n;i++){
			if(v[i].l<=R){
				R=min(R,v[i].r);
			}
			else{
				R=v[i].r;
				ans++;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
