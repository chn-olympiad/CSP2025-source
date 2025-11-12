#include<bits/stdc++.h>
using namespace std;
char b[1000005];
int c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
		b[c]=a[i];
		c++; 
		}
	}
sort(b,b+c+1);
	for(int i=c;i>0;i--){
		cout<<b[i];
	}
	return 0;
}

