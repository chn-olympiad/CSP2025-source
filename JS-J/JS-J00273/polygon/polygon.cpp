#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5001],b[5001],maxx,summ,ans,cnt,n,MOD=998244353;
void qwer(int c){
	if(!c) return;
	b[++cnt]=a[c];
	summ+=a[c];
	int ma=maxx;
	maxx=max(maxx,a[c]);
	if(maxx*2<summ && cnt>=3){
		ans+=1<<(c-1);
		ans%=MOD;
	}
	else qwer(c-1);
	cnt--;
	summ-=a[c];
	maxx=ma;
	qwer(c-1);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	qwer(n);
	cout<<ans;
	return 0;
}
