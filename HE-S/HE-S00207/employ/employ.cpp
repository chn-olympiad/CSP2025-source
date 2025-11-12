#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=100&&m<=n){
		long long m1=1;
		long long n1=1;
		for(int i=1;i<=n;i++){
			n1*=i;
		}
		for(int i=1;i<=m;i++){
			m1*=i;
		}
		long long x=1;
		for(int i=1;i<=n-m;i++){
			x*=i;
		}
		cout<<(n1/(m1*x))%998244353;
	}else if(n>=200&&n<=500&&m<=n){
		long long m1=1;
		long long n1=1;
		for(int i=1;i<=n;i++){
			n1*=i;
		}
		for(int i=1;i<=m;i++){
			m1*=i;
		}
		long long x=1;
		for(int i=1;i<=n-m;i++){
			x*=i;
		}
		cout<<n1/(m1*x);
	}else if(n>=200&&n<=500&&m==n){
		for(int i=0;i<n;i++){
			
		}
	}
	return 0;
}
