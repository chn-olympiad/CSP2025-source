#include<bits/stdc++.h>
using namespace std;
const int N=1000100;
int n,a[N],t[10];
char s[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int i=1;
	while(scanf("%c",&s[i])==1){
		if(s[i]>='0' and s[i]<='9'){
			a[i]=s[i]-'0';
			t[a[i]]++;
		}
	}
	int k=0;
	for(int j=9;j>=1;j--){
		if(t[j]==0)k++;
	}
	if(k==9 and t[0]!=0){
		cout<<0;
		return 0;
	}
	for(int j=9;j>=0;j--){
		while(t[j]>0){
			printf("%d",j);
			t[j]--;
		}
	}
	return 0;
} 
