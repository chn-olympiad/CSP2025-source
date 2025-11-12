#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(int(s[i])>=48&&int(s[i]<=57)){
			a[c]=s[i];
			c++;
		}
	}
	for(int i=0;i<c-1;i++){
		for(int j=0;j<c-1;j++){
			if(a[j]<a[j+1]){
				int b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
			}
		}
	}
	for(int i=0;i<c;i++){
		cout<<a[i]-48;
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
} 
