#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
long long ans;
bool s[505],vis[505];
char ss[505];
void dfs(int f,int sum,int z){
	if(f>n){
		if(sum>=m)ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(z>=c[i]||s[i]==0)dfs(f+1,sum,z+1);
			else dfs(f+1,sum+1,z); 
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> ss[505];
		s[i]=ss[i]-'0';
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	
	if(m==1){
		ans=1;
		int f=0;
		for(int i=1;i<=n;i++){
			if(c[i]==1){
				f=i;
				break;
			}
		}
		f--;
		sum=0;
		for(int i=1;i<=n;i++){
			if(i!=n)ans*=i;
			ans%=998244353;
			if(c[i]>f)sum++;
		}
		ans*=sum;
		ans%=998244353;
		cout<<ans<<endl;
	}else{
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}
