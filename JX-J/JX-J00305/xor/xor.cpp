#include<bits/stdc++.h>
using namespace std;
int b[5005][5005],c[50000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,i1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a==1)i1++;
	}
	if(n==i1){
		if(n==1){
			if(m!=1) cout<<0;
			else cout<<1;
		}
		if(n==2) cout<<1;
		if(n>2){
			int n1=n/2,n2=0;
			for(int i=1;i<=n1;i++){
				n2+=n/i/2;
			}
			cout<<n2;
		}
		
	}
	return 0;
}
