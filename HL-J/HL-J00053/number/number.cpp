#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[100005],c[100005];
int n,d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=8;i++){
		cin>>a[i];
		n=a[i];
		b[i]=n;
		if(b[i]>=48&&b[i]<=57){
			c[i]=b[i]-48;
			cout<<c[i];
		}
	}
	return 0;
}
