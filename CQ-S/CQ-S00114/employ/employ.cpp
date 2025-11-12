#include<bits/stdc++.h>
using namespace std;
const int N=12;
const int mod=998244353;
int n,m,c[N],ans;
char s[N];
bool usd[N];

void dfs(int pos,int a[]){
	if(pos==n+1){
		int cnt=0,tot=n;
		for(int i=2;i<=pos;i++){
			if(cnt>=c[a[i]]||s[a[i]-1]=='0')tot--,++cnt;
		}
		ans+=(tot>=m);
		ans%=mod;
	}
	for(int i=1;i<=n;i++){
		if(!usd[i]){
			a[pos+1]=i;usd[i]=1;
			dfs(pos+1,a);
			a[pos+1]=0;usd[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int s[12]={0};
	dfs(1,s);
	cout<<ans<<'\n';
	return 0;
}
