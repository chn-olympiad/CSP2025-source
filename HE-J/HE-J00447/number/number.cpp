#include<bits/stdc++.h>
using namespace std;
char a[1000005]={};
int b[1000005];
bool cmd(int a,int b){
	return a>b;
}
int main(){
	int j=1;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a+1;
	for(int i=1;i<=1000005;i++){
		if(a[i]>=48&&a[i]<=57){
		b[j++]=a[i]-48;
		}
		if(a[i]==' ')break;
	}
	sort(b+1,b+j,cmd);
	for(int i=1;i<j;i++)
	cout<<b[i];
	return 0;
}
