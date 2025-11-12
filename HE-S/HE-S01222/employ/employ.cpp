#include<bits/stdc++.h>
using namespace std;
string s;
long long p;
int suan(long long n,long long m,long long nn[],int z){
	if(z==n){
		return 0;
	}
	long long mi=0,ms=0;
	for(long long i=0;i<n;i++){
		long long ii=0;
		int i2=s[i]-'0';
		if(i2==1 and ms<nn[i]){
			mi++;
		}else{
			ms++;
		}
	}
	if(mi>=m){
		p++;
	}
	suan(n,m,nn,++z);
	return 0;
}
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	cin>>s;
	long long nn[n];
	for(long long i=0;i<n;i++){
		cin>>nn[i];
	}
	suan(n,m,nn,0);
	cout<<p;
	return 0;
}
