#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
void dfs(int curr,int mx,int s,int c,vector<int> a,int n,bool nch){
	
	//cout << 'n' << curr << "mx" << mx << "s" << s << "c" << c << endl; 
	if(c>=3 && (2*mx < s) && nch){
		ans++;
		ans %= 998244353;
		//cout << "ans++ " << curr << endl;
	}
	if(curr>n)return;
	//cout << "nc\n";
	dfs(curr+1,mx,s,c,a,n,0);
	//cout << "ch\n";
	dfs(curr+1,max(mx,a[curr]),s+a[curr],c+1,a,n,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	vector<int> a(n+1);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1,0,0,0,a,n,0);
	cout << ans;
	return 0;
} 
