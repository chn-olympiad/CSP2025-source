#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,w=-1;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-k;i++){
		w=max(a[i],w);
	}
	cout<<w;
	return 0;

}
