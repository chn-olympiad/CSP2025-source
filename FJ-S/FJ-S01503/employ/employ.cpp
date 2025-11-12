#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],a[510],b[510],d[510],cnt=0,ans=0;
string s;
bool pd=1;
void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;i++){
			if((a[i-1]==1)&&((i-cnt-1)<c[d[i]])){
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
			ans%=998244353;
		}
		cnt=0;
		return ;		
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			d[x]=i;
			dfs(x+1);
			b[i]=0;
			d[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.length();i++){
		a[i]=s[i]-'0';
		//if(!a[i]){
		//	pd=false;
		//}
	}
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	//if(pd==true){
	//	long long res=1;
	//	for(int i=2;i<=n;i++){
	//		res*=i;
	//		cout<<res<<endl;
	//		res%=998244353;
	//	}
		
	//	cout<<endl<<res;
	//	return 0;
	//}
	dfs(1);
	cout<<ans;
	return 0;
} 
