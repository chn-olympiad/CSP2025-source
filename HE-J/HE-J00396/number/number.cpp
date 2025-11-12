#include<bits/stdc++.h>
using namespace std;
string a;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int b[a.size()]={0},c=0;
	for(int i=0;i<a.size();i++){
		if(int(a[i])-48>=0 && int(a[i])-48<=9){
			b[c]=int(a[i])-48;
			c++;
		}
	}
	sort(b,b+c,cmp);
	for(int i=0;i<c;i++)cout<<b[i];
	return 0;
}
