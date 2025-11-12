#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool p;
	long long n,m,b=0,e=0;
	cin>>n>>m;
	long long a[n+1],c[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		p=true;
		if(a[i]==m&&p==true){
			b++;
			p=false;
		}
		for(long long j=1;j<=n;j++){
			c[j]=a[j];
	}
		for(long long j=i+1;j<n;j++){
			if(c[j]==m)break;
			e=c[i]^c[j+1];
			if(e==m&&p==true){
				b++;
				p=false;
				i=j;
				break;
				}
			else if(e!=m&&p==true)c[j+1]=e;
			}
	}
	cout<<b;
	return 0;
}
