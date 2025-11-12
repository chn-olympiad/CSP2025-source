#include<bits/stdc++.h> 
using namespace std;
long long a[1000];
char s[10000];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	gets(s);
	long long  k=0,f=0,temp;
	long long answer=0; 
	while(s[k]!='\0'){
		if(s[k]-'0'<=9&&s[k]-'0'>=0) {
		a[f]=s[k]-'0';
		f++;
		}
		k++;
	}
	for(int i=0;i<=f;i++){
	for(int j=i;j<=f;j++){
		if(a[i]<a[j]){
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
		}
	}


	}
	for(int i=0;i<f;i++){
	answer=answer*10+a[i];
	}
	cout<<answer;
	return 0;
}
