#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],v[505],ans;
string s;
void dfs(int x,int k,int d){
	int f = 0;
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			f = 1;
		}
	}
	if(!f){
		if(k>=m){
			ans++;
		}
		return;
	}
	while(f){
		f = 0;
		for(int i=1;i<=n;i++){
			if(v[i]==0){
				if(c[i]<=d){
					v[i] = 1;
					d++;
					f = 1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i] = 1;
			if(s[x]=='1')
				dfs(x+1,k+1,d);
			else
				dfs(x+1,k,d+1);
			v[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	sort(c+1,c+n+1);
	dfs(0,0,0);
	cout << ans+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
