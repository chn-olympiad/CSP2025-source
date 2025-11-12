#include<bits/stdc++.h>
using namespace std;
const long long int MODD=998244353;
int n,m;
string s;
int c[505];
long long int ppp(int x){
	long long int ans;
	for(int i=1;i<=x;i++){
		ans=ans*i%MODD;
	}
} 
int main(){
	//freopen("employ.in","r",stdin)
	//freopen("employ.out","w",stdout)
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	if(m==1){
			 
	} 
	else{
		cout<<ppp(n);
	}
	return 0;
}

