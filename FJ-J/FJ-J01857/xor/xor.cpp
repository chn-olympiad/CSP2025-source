#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500020],onum,znum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]==0)	znum++;
		if(a[i]==1)	onum++;
	}
	if(k==0)	cout <<znum;
	if(k==1)	cout <<onum;
	return 0;
} 
