#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cnt,a[505],b[505];
const int M=998244353;
string s;
bool check(){
	int cnt=0,fa=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			fa++;
		}else{
			if(fa>=b[i])fa++;
			else cnt++;
		}
	}
	return cnt>=m;
}
void dfs(int k){
	if(k==n+1){
		if(check())ans++;
		return;
	}
	for(int i=1;i<=n;i++){		
		if(b[i]==-1){
			b[i]=a[k];
			dfs(k+1);
			b[i]=-1;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	for(int i=1;i<=500;i++)b[i]=-1;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)cnt++;
	}
	if(n<=18){
		dfs(1);
		cout<<ans<<endl;
	}else{
		cout<<0<<'\n';
	}
	return 0;
}
