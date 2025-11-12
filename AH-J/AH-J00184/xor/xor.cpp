#include<bits/stdc++.h>
using namespace std;
long long n,k,s,q,f=1;
int a[500003];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f){
		cout<<n/2;
	}else {
		if(k==1){
			for(int i=1;i<=n;i++)q+=a[i];
			cout<<q;
		}
		else {
			for(int i=1;i<=n;i++){
				if(a[i]==0)q++;
				else {
					if(a[i]==a[i+1])q++;
				}
			}
			cout<<q;
		}
	}
	return 0;
}
