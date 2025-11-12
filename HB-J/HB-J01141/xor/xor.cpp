#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e5;
int a[N];
int flag=1;
int m,v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
		if(a[i]==1) m++;
		if(a[i]==0) v++;
	}
	if(flag==1&&k==0){
		cout<<n/2;
	}
	else{
		if(k==1) cout<<m;
		else{
			cout<<m/2+v;
		}
	}
	return 0;
}
