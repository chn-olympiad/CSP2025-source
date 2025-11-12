#include<bits/stdc++.h>
using namespace std;

int a,c,d;
int b[1000060];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(a!=0){
		b[c]=a%10;
		a/=10;
		c++;
	}
	for(int i=2;i<c;i++){
		for(int j=i;j>=2;j--){
			c=b[j]+b[j-1];
			b[j-1]=max(b[j],b[j-1]);
			b[j]=c-b[j-1];
		}
	}
	for(int i=0;i<c;i++){
		cout<<b[i];
	}
	return 0;
}
