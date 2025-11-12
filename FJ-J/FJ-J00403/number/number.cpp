#include<bits/stdc++.h>
using namespace std;
int main(){
	int c[10000000]={},j=0,p=0;
	string a;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int b=0;b<a.size();b++){
		p=a[b]-'0';
		if(p>=0&&p<=9){
		c[j]=a[b]-'0';
		j++;
	}
	}
	sort(c,c+j);
	for(int b=j-1;b>=0;b--){
		cout<<c[b];
	}
	fclose(stdin);
	fclose(stdout);
}
