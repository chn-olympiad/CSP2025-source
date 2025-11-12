#include<bits/stdc++.h>
using namespace std;
int a[10],i;
char n[10001];
int main(){
	scanf("%s",n);
	while(n[i]!='\n'){
		if(n[i]>='0'){a[n[i]-'0']++;}
		i++;
	}
	a[3]--;
	for(int j=9;j>=0;j--)
	    for(int z=0;z<a[j];z++)
	        cout<<j;
	return 0;
} 