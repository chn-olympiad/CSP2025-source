#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int i,j,b,a[10]={0};
	for(i=0;i<s.size();i++){
		if((int)s[i]>=48 && (int)s[i]<=57){
			b=(int)s[i]-48;
			a[b]+=1;	
		}
	}
	for(i=9;i>=0;i--){
		if(a[i]!=0){
			for(j=0;j<a[i];j++){
				cout<< i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
