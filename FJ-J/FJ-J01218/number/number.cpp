#include<bits/stdc++.h>
using namespace std;
char a[1000000],c[1];
int b[1000001],b1=0,a1=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<1000000;i++)
		if(a[i]==c[0])break;
		else a1++;
	for(int i=0;i<=a1;i++)
		if(int(a[i])>=48&&int(a[i])<=57){
			b1++;
			b[b1]=int(a[i])-48;
		}
	sort(b+1,b+b1+1);
	for(int i=b1;i>=1;i--)cout<<b[i];
	return 0;
}
