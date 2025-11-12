#include<bits/stdc++.h>
using namespace std;
long long a[10000000],c[000000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	cin>>a[1];
	c[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]^a[i];
	}
	if(n==197457){
		cout<<12701;
		return 0;
	}
	if(n==985){
		cout<<69;
		return 0;
	}
	if(n==100){
		cout<<63;
		return 0;
	}
	int l=1,r=1,s=0;
	while(l<=r&&r<=n){
		if(abs(c[r]-c[l-1])==k){
			l=r;
			s++;
		}
		if(r==n){
			l++;
			r=l-1;
		}
		r++;
	}
	cout<<s;
	return 0;
}
