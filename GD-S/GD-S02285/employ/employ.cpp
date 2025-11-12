#include<bits/stdc++.h>
using namespace std;
long long INF=998244353;
long long countt(long long n,long long m){
	long long sum=1;
	if(n>m)swap(n,m);
	for(int i=n;i<=m;i++){
		sum*=i;
		sum%=INF;
	} 
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	cout<<countt(n,m);
}
