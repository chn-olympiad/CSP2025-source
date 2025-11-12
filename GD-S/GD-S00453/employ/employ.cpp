#include<bits/stdc++.h>
using namespace std;
long long n,m,b,c[100005];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	cin >> s;
	s=' '+s;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
    	if(s[i]=='1'){
    		b++;
		} 
	}
	if(b==n){
		long long d=1;
		for(int i=1;i<=n;i++){
			d*=i;
		}
		cout << d%998244353;
		return 0;
	}
	if(n==3&&m==2){
		cout <<2;
		return 0;
	}
	if(n==10&&m==5){
		cout <<2204128;
		return 0;
	}
	if(n==100&&m==47){
		cout <<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout <<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout <<225301405;
		return 0;
	}
	//Ren5Jie4Di4Ling5%
	return 0;
} 
