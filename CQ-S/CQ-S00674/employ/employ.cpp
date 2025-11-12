#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],sum1,sum0,v[1005],ans;
string s;
void dfs(int id,int lq,int tt){
	if(lq>=m){
		ans++;
		cout<<endl;
		return ;
	}
	if(id==n+1){
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;cout<<i;
			dfs(id+1,lq+int(tt<a[i]&&s[id-1]=='1'),tt+int(tt>=a[i]||s[id-1]!='1'));
			
			v[i]=0;
		}
	} 
	return ;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
	}else if(m==n){
		int f=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||s[i-1]=='0'){
				f=1;break;
			}
		}
		if(f==1){
			cout<<0;
			return 0;
		}
		int sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
	}else if(n<=10){
		dfs(1,0,0);
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
