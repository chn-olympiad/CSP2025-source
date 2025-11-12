#include<iostream>
#include<cstdio>
using namespace std;
string s;
int c[5001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i = 0;i<n;i++){
		cin>>c[i];
	}
	long long ans = 1;
	for(int i = 1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
}
