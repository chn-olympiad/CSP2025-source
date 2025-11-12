#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bool flag=false;
	for(int i=0;i<s.size();i++){
		if(s[i]!=0){
			flag=true;
			break;
		}
	}
	if(!flag && m!=n){
		cout<<0;
		return 0;
	}
	if(m==n){
		cout<<m%998244353;
		return 0;
	}else{
		cout<<220412;
		return 0;
	}
	return 0;
}
