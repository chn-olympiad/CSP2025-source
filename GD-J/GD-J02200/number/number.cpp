#include<bits/stdc++.h>
using namespace std;
char a[1000009];
map<int,int>b;
int u=0;
int main(){	
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	cin>>a;
	int l=strlen(a);
	for(int i=0;i<l;i++){
		if(a[i]-'0'<=9){
		b[int(a[i]-'0')]++;	
		u=max(u,int(a[i]-'0'));
		}
	}
	if(u>0){
	for(int i=9;i>=0;i--){
			for(int j=1;j<=b[i];j++)cout<<i;
	}	
	}else{
		cout<<0;
	}
	return 0;
}
