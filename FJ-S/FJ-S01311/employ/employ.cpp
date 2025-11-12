#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[550],c[550],n,m,x[550];
int power(int n){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	return ans;
}
int dfs(int p,int wait,int ans){
	if(ans>=m){ 
		return power(n-p+1);
	}
	if(m-ans>n-p+1)return 0;
	int rans=0;
	for(int i=1;i<=n;i++){
		int flag=0;
		if(x[i]==0){
			if(c[i]>wait && a[i]==1){
				ans++;
				flag=1;
			}
			else{
				wait++;
				flag=2;
			}
			x[i]=1;
			rans+=dfs(p+1,wait,ans);
			rans%=998244353;
		}
		x[i]=0;
		if(flag==1)ans--;
		if(flag==2)wait--;
	}
	return rans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]-48;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<dfs(1,0,0)%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
