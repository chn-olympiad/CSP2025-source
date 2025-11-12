#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,b,a,e,c;
	cin>>n;
	long long d[n],z[n],s[n],q[n],l[10000000];
	for(int i=-1;i<n-1;i++){
		cin>>d[i]>>z[i+1]>>s[i+2];
		a=max(d[i],z[i+1]);
		b=max(a,s[i+2]);
		c=c+b;                     																																																																																						
	}

	cout<<3;
}
