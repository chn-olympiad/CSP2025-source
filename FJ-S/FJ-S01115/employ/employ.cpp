#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans;
string s;
int c[505];
int b[505];
void dfs(int r,int cnt,int meiguo){
	if(r>n) return;
	if(cnt==m){
		ans=(ans+1)%mod;
//		cout<<"ans++"<<endl;
		return;
	}
	if(n-r+cnt<m) return;
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
//			cout<<r<<" "<<cnt<<" "<<meiguo<<" "<<i<<endl;
			if(meiguo>=c[i]){
				dfs(r+1,cnt,meiguo+1);
			}
			else{
				if(s[r]=='0'){
					dfs(r+1,cnt,meiguo+1);
				}
				else{
					dfs(r+1,cnt+1,meiguo);
				} 
			}
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
	int flag=1,len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			flag=0;
			break;
		}
	}
	if(flag){
		 long long ans=1,sum=1;
		if(m>n-m){
			for(int i=m+1;i<=n;i++) ans*=i;
			for(int i=1;i<=n-m;i++) sum*=i;
			cout<<ans/sum;
		}
		else{
			for(int i=n-m+1;i<=n;i++) ans*=i;
			for(int i=1;i<=m;i++) sum*=i;
			cout<<ans/sum;
		}
		return 0;
	}
	else if(n<=12){
		dfs(0,0,0);
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
