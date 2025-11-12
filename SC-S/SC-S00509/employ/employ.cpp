#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
string s;
int jc(int n){
	int cnt=1;
	for(int i=1;i<=n;i++){
		cnt=(cnt*i)%998244353;
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		if(s[i]=='1'){
			cout<<0;
			return 0;
		}
	}
	cout<<jc(n);
	return 0;
}//rp++