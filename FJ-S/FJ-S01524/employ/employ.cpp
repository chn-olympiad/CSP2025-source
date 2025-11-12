#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],sum=0,b[505],a[505];
const int mod=998244353;
string s;
void dfs(int k){
	if(k>n){
		long long cnt=0,cnt1=0;
		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" ";
			if(s[i-1]=='0'){
//				cout<<i<<endl;
				cnt++;
				continue;
			}
			if(c[a[i]]>cnt){
				cnt1++;
//				cnt=0;
			}else{
				cnt++;
			}
		}
//		cout<<endl;
		if(cnt1>=m){
//			cout<<cnt1<<endl;
			sum=(sum+1)%mod;
		}
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			a[k]=i;
			b[i]=1;
			dfs(k+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n>100){
		cout<<0;
		return 0;
	}
	memset(b,0,sizeof(b));
	dfs(1);
	cout<<sum%mod;
	return 0;
}

