#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000010]={0},i=0;
	char s;
	scanf("%c",&s);
	while(s!='\n'){
		if(s>=48&&s<=57){
			a[i]=s-48;
			i++;
		}
		scanf("%c",&s);
	}
	for(int j=0;j<i;j++){
		for(int l=0;l<i-1;l++){
			if(a[l]<a[l+1]){
				int x=a[l];
				a[l]=a[l+1];
				a[l+1]=x;
			}
		}
	}
	for(int l=0;l<i;l++){
		printf("%d",a[l]);
	}
	return 0;
}
