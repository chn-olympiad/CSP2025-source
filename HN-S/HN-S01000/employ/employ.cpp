#include<bits/stdc++.h>
using namespace std;
const long long N=500,MOD=998244353; 
long long n,k;
string s;
long long a[N],xu[N],cnt,b[N];
bool tong[N];
void dfs(int x){
	if(x>n){
		memset(b,0,sizeof(b));
		int sum=0,k=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				k++;
			}else if(a[xu[i]]>k){
				sum++;
			}else{
				k++;
			}
		}
		if(sum>=k) cnt++;
		cnt%=MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(tong[i]==0){
			tong[i]=1;
			xu[x]=i;
			dfs(x+1);
			tong[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k>>s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	bool op=1;
	for(long long i=0;i<s.size();i++){
		if(s[i]!='1') op=0;
	}
	if(op){
		cnt=1;
		for(long long i=2;i<=n;i++){
			cnt*=i;
			cnt%=MOD;
		}
		cout<<cnt%MOD;
		return 0;
	}
	dfs(1);
	cout<<cnt%MOD;
	return 0;
}

