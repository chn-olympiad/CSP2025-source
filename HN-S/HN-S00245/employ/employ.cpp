#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
bool s[505];
long long c[505];
const long long mod=998244353;
long long jc(int x){
	int k=1;
	for(int i=1;i<=x;i++){
		k=k*i%mod;
	}
	return k;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c=getchar();
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long int k=1;
	for(int i=1;i<=n;i++){
		k=(k*i)%mod;
		if(k==161088479){
			cout<<"there:k"; 
		}
	}
	cout<<k;
}
