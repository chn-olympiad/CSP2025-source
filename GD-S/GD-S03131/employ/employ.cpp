#include<bits/stdc++.h>
using namespace std;
#define int long long
int q[501],c[501];
string s;
int solve(int n){
	for(int i=1;i<=n;i++){
		res*=n;
		res%=998244353;
	}
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int sum=0;
	for(int i=0;i<n;i++)q[i+1]=s[i]-'0',sum+=q[i+1];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		int f=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0||q[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<solve(n);
	}
	return 0;
} 
