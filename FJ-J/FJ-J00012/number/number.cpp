#include<bits/stdc++.h>
using namespace std;
int b[100],c[100],d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a=0;
	cin>>a;
	for(int i=1;;i++)
	{
		b[i]=a%10;
		a=a/10;
		if(a==0){
			a=i;
			break;
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			if(b[j]>c[i]){
			c[i]=b[j];
			d=j;
		}
		}
		b[d]=0;
	}
	for(int i=1;i<=a;i++){
		cout<<c[i];
	}
	return 0;
}