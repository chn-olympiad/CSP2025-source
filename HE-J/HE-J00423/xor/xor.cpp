#include<bits/stdc++.h>
using namespace std;
int s[550000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,k,l=0;
	cin>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			int n=0;
			for(int k=i;k<=j;k++){
				n^=s[k];
			}
			if(n==k){
				l=max(l,n);
			}
		}
	}
	cout<<l;
	return 0;
}
