#include <bits/stdc++.h>
using namespace std;
long long ss=0,xx6;
int n,m;
string s;
int a[102010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	cin>>s;
	bool f=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') f=false;
	}for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				xx6=i;
				break;
			}
		}for(int i=1;i<=n;i++){
			if(a[i]>=xx6){
				cout<<a[i]<<endl;
				ss++;
			}
		}cout<<ss;
	}else if(n==m){
		if(!f){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	else{
		ss=1;
		if(f){
			for(int i=n;i>m;i--){
				ss*=i;
			}
			cout<<ss%998244353;
		}
		else{
			cout<<m;
		}
	}
	return 0;
}
