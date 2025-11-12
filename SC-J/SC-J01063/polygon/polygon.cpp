#include<bits/stdc++.h>
using namespace std;
int a[5001],b[5002];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i+1]=b[i]+a[i];
	}
	if(n<=3){
		if(n==3){
			int t1=b[4]-b[1],nao=0;
			for(int i=1;i<=3;i++)
				nao=max(nao,a[i]);
			if(t1>2*nao)
				cout<<1;
			else cout<<0;
		}
		else cout<<0;
	}
	return 0;
}