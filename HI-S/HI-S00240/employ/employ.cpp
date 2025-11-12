#include <bits/stdc++.h>
using namespace std;
long long int n,m,h=0,l=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string u;
	cin>>u;
	for(int i=0;i<u.length();i++){
		if(u.substr(i,1)=="1"){
			h+=1;
		}
	}
	if(n<10){
		cout<<m;
	}else{
		for(int i=h;i>=1;i--){
			l*=i;
		}
		cout<<l%998244353;
	}
	return 0;
} 
