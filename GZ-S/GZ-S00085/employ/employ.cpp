//GZ-S00085 遵义市汇川区第三小学 吴昊然 
#include <bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
string s;
long long a[505],ans=0;
bool f[505];
void dfs(int c,int x){
	if(x==n){
		if(sum>=m){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(f[i]==0){
			f[i]=1;
			if(s[i]=='1'&&c<a[i]){
				sum++;
				dfs(c,x+1);
				sum--;
			}else{
				x++;
				dfs(c+1,x+1);
			}
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

