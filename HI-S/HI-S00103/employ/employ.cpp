#include<bits/stdc++.h>
using namespace std;
int n,m;string s;int t,js;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t!=0){
			js++;
		}
	}
	long long int q=1;
	for(int i=js;i>=js-m;i--){
		q=q*i%998244353;
	}
	for(int i=1;i<=n-m;i++){
		q=q*i%998244353;
	}
	cout<<q;
	return 0;
}
