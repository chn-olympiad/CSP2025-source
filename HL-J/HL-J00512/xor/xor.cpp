#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=m;i++){
		b[i]=a[i];
	}for(int i=1;i<=m;i++){
		if(b[i]>max)
		max=b[i];
	}cout<<max;
	return 0;
}
