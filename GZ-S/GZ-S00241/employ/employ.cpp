//GZ-S00241 安顺市第二高级中学 李舜杰 
#include<bits/stdc++.h>
#define N 505
typedef long long  LL;
using namespace std;
const int mod=998244353;
LL n,m,c[N],a[N],a1;
LL ans,ed[N];
string s;
void dfs(LL deep,LL ac){
	if(deep>n){
		if(ac>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!ed[i]){
			ed[i]=1;
			if(a[deep]==0){
				dfs(deep+1,ac);
			}else{
				if(deep-1-ac>=c[i]){
					dfs(deep+1,ac);
				}else{
					dfs(deep+1,ac+1);
				}
			}
			ed[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie();cout.tie();

    cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]-'0';
		if(a[i]==1) a1++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(a1<m){cout<<0<<endl;return 0;
	}
	dfs(1LL,0LL);
	cout<<ans<<endl;
	return 0;
}

