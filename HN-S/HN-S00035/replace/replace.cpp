#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505;
const int MOD=998244353;
int m,n,cnt,a[maxn],ans[maxn],sum[maxn];
int len;
string s;
bool check(){
	int b=0,res=0;
	for(int i=1;i<=len;++i){
		if(s[i]=='0'){
			b+=ans[i];
		}
		else{
			for(int j=sum[i-1];j<=sum[i];++j){
//				cout<<j<<' ';
				if(b<a[j]){
					res++;
				}
			}
		}
	}
//	cout<<endl;
	return res>=m;
}
void dfs(int cur,int suma){
	if(suma>n){
		return ;
	}
	if(cur==len&&suma<=n){
		if(check()){
			cnt++;
			cnt%MOD;
		}
		return ;
	}
	for(int i=1;i<=n;++i){
		ans[cur]=i;
		sum[i]=sum[i-1]+ans[cur];
		dfs(cur+1,suma+i);
		ans[cur]=0;
	}
	return ;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m>>s;
	len=s.size();
	s=" "+s;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<cnt%MOD;
	return 0;
}
/*
3 2
101
1 1 2
*/

