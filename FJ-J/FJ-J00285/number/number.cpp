#include<bits/stdc++.h>
using namespace std;
char a[1000086];
int c[1000086],b[100],m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;;i++){
		cin>>a;
		c[i]=a[i];
		if (a[i]=='\0');
			break;
		
	}
	for(int i=0;i<=1000086;i++){
		c[i]=a[i];
		if(c[i]>=48&&c[i]<=57) 
			b[c[i]-48]++;
	}
	int i=9;
	while(i>=0){
		if (b[i]>0){
			cout<<i;
			b[i]--;
		}
		else{
			i--;
		}
	}
	
	return 0;
}
