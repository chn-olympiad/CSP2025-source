#include<bits/stdc++.h>
using namespace std;
int n,p;
long long k;
int a[500010],b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]^b[i-1];
	}
	bool f=0;
	for(int i=1;i<=n;i++){
		if(b[i]==k){
			p=i;
			f=1;
			break;
		}
	}
	if(f==1){
		for(int i=p+1;i<n;i++){
			a[i+1]^=a[i];
		}
		if(a[n]==k){
			cout<<2;
			return 0;
		}
		else if(b[n]==k){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(f==0){
		if(b[n]==k){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}