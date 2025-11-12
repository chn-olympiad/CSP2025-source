#include<bits/stdc++.h>
using namespace std;

char s[1000005];
int a[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int l=strlen(s+1);
	int i;
	for(i=1;i<=l;i++){
		int x=s[i]-'0';
		if(x<=9 && 0<=x) a[x]++;
	}
	
	for(int j=1;j<=l;j++){
		for(int k=9;k>=0;k--){
			while(a[k]>0){
				cout<<k;
				a[k]--;
			}
		}
		 
	}
	return 0;
} 
