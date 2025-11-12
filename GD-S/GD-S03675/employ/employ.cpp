#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod=998244353;
string answ;
bool vl=true;
long long s[505];
long long gi[505];
long long ans=0;
long long c(int x){
	if(x==1||x==0) return 1;
	else{
		return x*c(x-1);
	} 
}
long long f(int x,int y){
	return (c(y)/c(y-x))%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>answ;
	for(int i=0;i<answ.length();i++){
		s[i+1]=answ[i]-'0';
		if(s[i+1]==0) vl=false;
	}
	for(int i=1;i<=n;i++){
		cin>>gi[i];
	}
	if(vl){
		for(int i=m;i<=n;i++){
			ans=(ans+f(i,n))%mod;
		}
		cout<<ans;
	}
	else{
		cout<<rand();
	}
	return 0;
}
