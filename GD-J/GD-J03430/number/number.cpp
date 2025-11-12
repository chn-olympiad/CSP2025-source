#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100010]={};
	int n=0;
	int num[1010];
	gets(s);
	for(int i=0;i<sizeof(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[n]=s[i]-'0';
			n++;
		}
	}
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			if(num[j]<num[j+1]){
				swap(num[j],num[j+1]);
			}
			}
	}
	for(int i=0;i<n;i++) cout<<num[i];
	cout<<endl;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
