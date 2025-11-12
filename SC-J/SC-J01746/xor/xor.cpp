#include<bits/stdc++.h>
using namespace std;
int  n,k,a[500005],t=0;
int xo(int l,int r){
	int s=a[l];
	for(int i=l;i<r;i++){
		if(s!=a[i+1]) s=1;
		else s=0;
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(xo(i,j)==k) t++,i=j+1;
	cout<<t;
	return 0;
}