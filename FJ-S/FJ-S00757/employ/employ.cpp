#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],d,a;
string s;
bool b=true;
int main(){
	freopen("employ.in","r","stdin");
	freopen("employ.out","w","stdout");
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i-1]!='1'){
			b=false;
		}
		if(c[i]==0){
			d++;
		}
	}
	if(b){
		a=1;
		for(int i=n-d;i>=1;i--){
			a*=i;
			a%=998244353;
		}
		cout<<a/2;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	return 0;
}
