#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n,k,s0=0,s1=0;
	cin>>n>>k;
	vector<int> a(n+1);
	vector<bool> vis(n+1);
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) s0++;
		if(a[i]==1) s1++;
	}for(int i=1;i<=n;i++){
		if(a[i]==1&&a[i-1]==1){
			s0++;
			i++;
		} 
	}
	if(k==0) {cout<<s0;return;}
	if(k==1) {cout<<s1;return;}
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
