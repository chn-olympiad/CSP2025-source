#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	char s[10000000];
	int n[10000000];
	int zz=0;
	for(int i=0;i<=10000000;i++){
        cin>>s[i];
	}
	for(int i=0;i<=10000000;i++){
		if(s[i]-'0'==0||s[i]-'0'==1||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9){
			n[i]=s[i]-'0';
		}
	}
	for(int i=0;i<=10000000;i++){
		for(int j=0;j<=10000000;j++){
			if(n[i]<n[j]){
				zz=n[i];
				n[i]=n[j];
				n[j]=zz;
				zz=0;
			}
		}
	}
	for(int i=0;i<=10000000;i++){
		cout<<n[i];
	}
	return 0;
}
