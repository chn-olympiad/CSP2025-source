#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long ans=1;
int f(int n){
	if(n==1) return 1;
	return n*f(n-1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) {
		int t;
		cin>>t;
		v.push_back(t);
	}
	cout<<f(n);
	return 0;
}
