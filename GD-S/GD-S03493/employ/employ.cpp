#include <bits/stdc++.h>
using namespace std;

int n,m,a[1000];
string s;
bool f=1;
int sum(int x){
	int ans=1;
	while(x>=1){
		ans=(ans*x)%998244353;
		x--;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]!='1') f=0;
	}
	if(f) cout<<sum(n);
	return 0;
} 
