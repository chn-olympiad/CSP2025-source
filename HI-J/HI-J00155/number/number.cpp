#include<bits/stdc++.h>
using namespace std;
int b[1000000];
char cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i];
		} 
	}
	sort(b,b+a.size(),cmp);
	for(int i=0;i<a.size();i++){
		cout<<char(b[i]);
	}
	return 0;
}
