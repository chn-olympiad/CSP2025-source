#include<bits/stdc++.h>
using namespace std;
int n,k,fff=0;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		int g=0,g1=0;
		for(int j1=0;j1<=i;j1++){
			g = g^a[j1];
		}
		for(int j=i+1;j<n;j++){
			g1 = g1^a[j];
		}
		if(g1==g){
			fff = max(fff,g);
		}
	}
	cout<<min(fff,k);
	return 0;
}
