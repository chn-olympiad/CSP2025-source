#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int t,n,m;
string s;
void solve();
int minn(int a,int b){
	return a>b?b:a;
}
int c(int n,int m){
	long long ans=1;
	for(int i=1;i<=m;i++){
		ans*=(n-i+1);
		ans%=M;
		
	}
	return ans;
	
}
int bu[514];
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>bu[i];
	cout<<c(n,m);
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}

