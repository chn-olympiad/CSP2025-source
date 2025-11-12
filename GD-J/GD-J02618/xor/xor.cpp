#include<bits/stdc++.h>
using namespace std;
int n,k,l,a[500005],o=0,ai[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=0;
		for(int j=i;j<=n;j++){
			l=l^a[j];
			if(l==k){
				o++;
				
			}
		}
	}
	cout<<o;
}
