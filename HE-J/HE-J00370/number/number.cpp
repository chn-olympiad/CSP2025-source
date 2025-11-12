#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r","stdin")
	freopen("number.out","w","stdout")
	int n=0,i;
	char s[10086];
	int a[10086];
	for(i=1;i<=1;i++){
		cin>>s[i];
		n++;	
}
	for(i=1;i<=n;i++){
		if(s[i]!=1&&s[i]!=2&&s[i]!=3&&s[i]!=4&&s[i]!=5&&s[i]!=6&&s[i]!=7&&s[i]!=8&&s[i]!=9){
			break;
		}else{
			a[i]=s[i];
		}
	}
		for(i=1;i<=n;i++){
		cout<<a[i];
		}
	return 0;
}
