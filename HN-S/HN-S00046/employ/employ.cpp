#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int a[501],bb[501];
bool q[501];
long long ans=0;
void dfs(int x,bool f[],int b[]){
	if(x==n+1){
		int last=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&i-last<=a[b[i]]){
				last=i;
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
			ans%=MOD;
		}
		return;
	}
	else {
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				f[i]=1;
				b[x]=i;
				dfs(x+1,f,b);
				b[x]=0;
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=30){
		dfs(1,q,bb);
		cout<<ans%MOD<<endl;
	}
	else {
		int nn=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				nn++;
			}
		}
		long long aans=1;
		if(nn>=m){
			for(int i=1;i<=n;i++){
				aans*=i;
				aans%=MOD;
			}
			cout<<aans<<endl;
		}
		else cout<<0;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%


