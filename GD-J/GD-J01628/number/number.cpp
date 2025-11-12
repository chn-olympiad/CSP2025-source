#include<bits/stdc++.h>
using namespace std;
char b[1000005];
int a[10],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int i=0;i<=1000000;i++){
		if(b[i]>='0'&&b[i]<='9'){
			n=b[i]-'0';
			a[n]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
