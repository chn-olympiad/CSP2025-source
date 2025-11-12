#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=1,cnt=1;
string s;
int a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}
