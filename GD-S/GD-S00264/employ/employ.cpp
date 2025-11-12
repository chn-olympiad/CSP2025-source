#include<bits/stdc++.h>
using namespace std;
int n,m,c[501];
long long ans;
string s;
bool a[501];
void f(int t,int pn){
	if(t>=n){
		if(pn>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=0;i<n;i++){
		int npn=pn+1;
		if(!a[i]){
			a[i]=1;
			if(t+1-pn<=c[i] and s[t]=='0'){
				f(t+1,npn);
			}
			else{
				f(t+1,pn);
			}
			a[i]=0;
		}
	}
}
int ex(int x){
	long long s=1;
	for(int i=0;i<x;i++){
		s*=(n-i);
		s%=998244353;
	}
	return s;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool t=true;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(s[i]!='1'){
			t=false;
			s[i]='1';
		}
		else{
			s[i]='0';
		}
	}
	if(t){
		for(int i=0;i<=n-m;i++){
			ans+=ex(i);
			ans%=998244353;
		}
	}
	else{
		f(0,0);
	}
	cout<<ans;
	return 0;
} 
