#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long ss=1,e=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			e++;
		}
	}
	for(int i=m;i>=1;i--){
		ss=ss*e%998244353;e--;
	}
	cout<<ss;
	return 0;
}
