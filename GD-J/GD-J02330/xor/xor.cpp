#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=(1<<21)+5;
int n,m;
int lst,ans;
int a[MAXN];
int p[MAXN];
int sum[MAXN];
int cnt[MAXM];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(cnt,0x3f3f3f3f,sizeof(cnt));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i]=n+1;
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=n;i>=1;i--){
		if(a[i]==m){
			p[i]=i;
			cnt[sum[i]]=i;
			continue;
		}
		int fnd=m^sum[i-1];
		if(cnt[fnd]<=n){
			p[i]=cnt[fnd];
		}
		cnt[sum[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(p[i]>n) continue;
		if(lst<i){
			ans++;
			lst=p[i];
		}else{
			if(lst>p[i]){
				lst=p[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
