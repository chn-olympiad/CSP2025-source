#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
	char s;
	int a[1000001], la=0;
	for(int i=1;;i++){
		scanf("%c", &s);
		if(s==' '||s=='\n'){
			break;
		}
		if((s-'0')/10==0){
				la++;
				a[la]=s-'0';
		}
	}
    for(int i=1;i<=la;i++){
		for(int j=i+1;j<=la;j++){
			if(a[i]<a[j]){
				int k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	if(a[1]!=0){
        for(int i=1;i<=la;i++){
    	    printf("%d", a[i]);
    	}
    } else{
    	printf("0");
	} 
	return 0;
} 