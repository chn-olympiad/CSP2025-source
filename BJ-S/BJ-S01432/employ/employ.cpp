#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=998244353;
int n,m,unpass,pass,ans,cnt;
string s;
int ch[N],c[N],b[N],use[N];
void dfs(int d){
	if(d==n+1){
		unpass=0,pass=0;
		for(int i=1;i<d;i++){
//			cout<<b[i]<<" "<<ch[i]<<endl;
			if(b[i]==1&&ch[i]>unpass){
				pass++;
			}
			if(b[i]==0||ch[i]<=unpass) unpass++;
		}
		if(pass>=m) ans++;
		return;
		
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			ch[d]=c[i];
			dfs(d+1);
			use[i]=0;
			
		}
	}
}
long long jc(int n){
	long long ans=1;
	for(int i=2;i<=n;i++){
		ans=ans%M*i%M;
	}
	return ans%M;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		b[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<s.size();i++){
		if(s[i]=='1') cnt++;
	}
	if(cnt==s.size()-1){
		cout<<jc(n)%M;
		return 0;
	}
	dfs(1);
	cout<<ans%M;
	return 0;
}
