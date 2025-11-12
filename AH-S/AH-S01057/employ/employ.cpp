#include<iostream>
using namespace std;
const long long mod=998244353;
long long n,m,b[1000];
bool a[1000];
long long f(long long a,long long b){
	long long r=1;
	for(long long i=a;i<=b;i++){
		r*=i;
		r%=mod;
	}
	return r;
}
int A(){
	int r=0;
	for(int i=1;i<=n;i++){
		if(a[i]) r++;
	}
	return r;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(A()==n){
		cout<<f(1,n);
	}else if(m==n){
		cout<<0;
	}else if(m==1){
		cout<<f(1,n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
