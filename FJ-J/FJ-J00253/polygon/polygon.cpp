#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
int n,ai[5005];
long long num,al,a,bestn;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai[i];
	}
	for(int i=1;i<=n;i++){
		a+=ai[i];
		if(ai[i]>bestn){
			bestn=ai[i];
		}
	}
	if(a>bestn*2){
		for(int i=1;i<=n;i++){
			num*=i;
		}
		cout<<num%998244353;
	}
	
	return 0;
}
