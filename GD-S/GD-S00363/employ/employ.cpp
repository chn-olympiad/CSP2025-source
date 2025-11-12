#include<bits/stdc++.h>
using namespace std;
long long n,m,p,a[90010],b[90010];
bool t[90010];
string s;
void dfs(long k){
	if(k>n){
		long c=0,l=0;
		for(long i=1;i<=n;i++){
			if(s[i-1]=='0'||c>=b[i]){
				c++;
			}else{
				l++;
				if(l>=m){
					p++;
				}
			}
		}
		return;
	}
	for(long i=1;i<=n;i++){
		if(t[i]==false){
			t[i]=true;
			b[k]=a[i];
			dfs(k+1);
			t[i]=false;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<p%998244353;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
