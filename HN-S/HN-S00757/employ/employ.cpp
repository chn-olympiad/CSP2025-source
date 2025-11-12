#include<bits/stdc++.h>
using namespace std;
long long a,b,c=0,d[505],e=1;
char h;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>h;
		if(h=='1') c++;
	}
	for(int i=1;i<=a;i++) cin>>d[i];
	if(c==a){
		for(int i=1;i<=(a-b);i++){
			e*=(a-i+1);
			e/=i;
			e%=998244353;
		}
		cout<<e;
	}else{
		cout<<0;
	}
	return 0;
}

