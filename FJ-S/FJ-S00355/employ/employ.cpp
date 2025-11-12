#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998224353;
int a[20];
bool f[20];
int n,m;
string s;
int prdr=0;
void dfs(int x,int num,int los){
	if(n-los<m)return;
//	cout<<x<<" "<<num<<" "<<los<<endl;
	if(x==n+1){
		if(num>=m)prdr+=1;
		prdr%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		f[i]=1;
		if(los<a[i]&&s[x-1]=='1'){
			num++;
			dfs(x+1,num,los);
			num--;
		}
		else{
			los++;
			dfs(x+1,num,los);
			los--;
		}
		f[i]=0;
	}
}
signed main(){
  	freopen("employ.in","r",stdin);
  	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<prdr;
	return 0;
}

