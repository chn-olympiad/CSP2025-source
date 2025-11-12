#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	string s;
	cin>>s;
	int l=s.size(),t=0;
	if(l==1){
		cout<<s;return 0;
	}
	char x[1000010];
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			x[t]=s[i];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=t;j++){
			if(x[j]<x[j+1]){
				int a=x[j];
				x[j]=x[j+1];
				x[j+1]=a;
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<x[i];
	}
	return 0;
}
