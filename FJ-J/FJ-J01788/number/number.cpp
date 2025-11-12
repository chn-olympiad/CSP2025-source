#include<bits/stdc++.h>
using namespace std;
char a[1000005];
long long b[1000005];
bool cmp(int a,int b){
	if(a>b){
		return true;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int xb=0;
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(int(a[i]-'0')>=0&&int(a[i]-'0')<=9){
			b[xb++]=int(a[i]-'0');
		}
	}
	sort(b,b+xb,cmp);
	for(int i=0;i<xb;i++){
		cout<<b[i];
	}
	return 0; 
}
