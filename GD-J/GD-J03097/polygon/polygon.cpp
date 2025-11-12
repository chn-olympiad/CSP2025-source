#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;
int n;
int a[5005];
ll cnt=0;

void dfs(bool get,int nxt,int sum,int maxx,int s){
	int cur=nxt;
	
	if(cur>n) return;
	
	if(get==true){
		maxx=max(maxx,a[cur]);
		s++;
		sum+=a[cur];
		if(sum>maxx*2 && s>=3){
			cnt++;
//			cout<<cur<<" "<<get<<" "<<s<<" "<<maxx<<" "<<sum<<endl;
		}
	} 
	dfs(true,cur+1,sum,maxx,s);
	dfs(false,cur+1,sum,maxx,s);
	return;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(true,1,0,-9,0);
	dfs(false,1,0,-9,0);
	cout<<cnt%MOD;
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
