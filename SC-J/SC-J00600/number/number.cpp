#include<iostream>
#include<cstring>
using namespace std;
char s[1000001];
int l,n;
int a[1000001];
int c[1000001];
int main(){	
	freopen("number.in","r",stdin);

	freopen("number.out","w",stdout);


	scanf("%s",s+1);
	l=strlen(s+1);


	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=s[i]-48;
			c[a[n]]++;
		}
	}

	for(int i=9;i>=0;i--){
	for(int j=1;j<=c[i];j++){
		cout<<i;
	}
	}
	
}