#include<bits/stdc++.h>
using namespace std;
char a[1000010]; 
int hsh[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			int b=a[i]-'0';
			hsh[b]++;
		}
	}

	for(int i=9;i>=0;i--){
		for(int j=1;j<=hsh[i];j++)cout<<i;
	}
	return 0;
}
