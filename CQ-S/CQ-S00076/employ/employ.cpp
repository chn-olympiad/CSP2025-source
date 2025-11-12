#include<bits/stdc++.h> 
using namespace std;
long long n,m,t[100000],ans=1;
string y;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>y;
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	for(int i=0;i<n;i++){
		ans=(ans*n)%998244353;}
	cout<<ans;
	return 0;
}
