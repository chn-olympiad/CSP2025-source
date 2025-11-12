#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[100001],m[100001]={};
	cin>>a;
	int len=strlen(a);
	int b[100001]={};
	for(int i=0;i<len;i++){
		b[i]=-1;
	} 
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i]-48;
		}
	}
	sort(b,b+len);
	for(int i=len-1;i>=1;i--){
		if(b[i]!=-1)cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
