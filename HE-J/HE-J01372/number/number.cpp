#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10000001],b=0,d=1,e=2,f;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'and s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	for(int j=0;j<b+1;j++){
		for(int d=1;d<b;d++){
			if(a[d]>a[d-1]){
				f=a[d];
				a[d]=a[d-1];
				a[d-1]=f;}}}
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
	}
