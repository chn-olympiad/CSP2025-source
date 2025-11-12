#include<bits/stdc++.h>
using namespace std;
int a[500001];
int b[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int z=0;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=(b[i-1] ^ a[i]);
	}
	for(int i=1,l=1;i<=n;i++){
		for(int j=l;j<=i;j++){
			if(((b[i] ^ b[j])==k&&i!=j)||(a[i]==k)){
				z++;
				l=j+1;
				i=l;
				break;
			}
		}
	}
	cout<<z;
	return 0;
}
