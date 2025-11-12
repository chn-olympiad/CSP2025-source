#include<bits/stdc++.h>
using namespace std;
const int MX=1000,INF=0x3f3f3f3f;
int flag[MX],c[MX],a[MX];
void solve(){
	int n,m;scanf("%d%d",&n,&m);
	string s;cin>>s;
	int ans=0;
	for(int i=1;i<=n;i++)  flag[i]=s[i-1]-'0',scanf("%d",&c[i]),a[i]=i;
	do{
		int sum=0;
		for(int i=1;i<=n;i++){
			if(sum>=c[a[i]]||flag[i]==0)  sum++;
		}
		ans+=(n-sum)>=m;
	}while(next_permutation(a+1,a+1+n));
	printf("%d",ans);
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	while(T--)  solve();
	return 0;
}
