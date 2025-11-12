#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,c,l;
	cin>>n;
	cin>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long t=0;
	bool flag=false;
	for(long long i=0;i<n;i++){
		long long s=a[i];
		for(long long j=n-1;j>i;j--){
			s=s^a[n-j-2];
			l=j-i-1;
			if(s==k&&l==max(t,l)){
				c=l;
				flag=true;
				t=c;
			}
		}
	}
	if(flag==false){
		for(long long i=0;i<n;i++){
			if(a[i]==k){
				cout<<"1";
			}
		}
	}else if(flag==true){
		cout<<c;
	}else{
		cout<<"0";
	}
	return 0;
}