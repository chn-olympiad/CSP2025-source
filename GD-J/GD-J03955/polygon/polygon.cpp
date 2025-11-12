#include<bits/stdc++.h>
using namespace std;
long long n,t[5200],z[5200],m[5200],sum,c,yq,ans;
void dfs(int x){
	for(int i=x;i<=n;i++){
		if(z[i]==0&&t[i]>=m[c]){
			z[i]=1;
			yq=t[i];
			sum+=t[i];
			c++;
			m[c]=t[i];
			if(x>=3&&sum>2*yq){
				ans++;
				ans%=998244353;
				dfs(x+1);
			}
			else{
				dfs(x+1);
			}
			z[i]=0;
			sum-=t[i];
			m[c]=0;
			c--;
			yq=m[c];
		}
	}
}
int main(){
	freopen("polygon.in","r".stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t[i];
	}
	sort(t+1,t+n+1);
	dfs(1);
	cout << ans;
	return 0;
}
