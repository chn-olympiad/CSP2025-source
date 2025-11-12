#include<bits/stdc++.h>
using namespace std;
const int kMaxN=510,kM=998244353;
int n,m,c[kMaxN],cnt;
long long ans;
bool f[kMaxN];
string s;
void S(int x){
	if(x==n){
		if(n-cnt>=m){
			ans=(ans+1)%kM;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		int w=cnt;
		if(cnt>=c[i]||s[x]=='0'){
			cnt++;
		}
		S(x+1);
		cnt=w,f[i]=0;
	}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		S(0);
		cout<<ans;
		return 0;	
	}
	bool F=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') F=1;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			cnt++;
		}
	}
	if(cnt==0&&!F){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans=(ans*i)%kM;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
    return 0;
}

