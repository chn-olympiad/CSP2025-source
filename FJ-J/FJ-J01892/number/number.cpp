#include<bits/stdc++.h>
using namespace std;
char s[1001000];
int a[1001000];
int n,tmp,b;
int main(){
	cin.getline(s,1001000);
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[b]=(int)s[i]-48;
			b++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]<=a[j+1]){
				tmp=a[j+1];
				a[j+1]=a[j];
				a[j]=tmp;
			}
		}
	}
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;  
}
