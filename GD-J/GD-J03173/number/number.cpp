#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=1e6+5;
int b[N];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int p=0;
	getline(cin,a);
	for(int i=0;i<=a.size();i++){
		if(a[i]=='9'){
			b[p++]=9;
		}if(a[i]=='8'){
			b[p++]=8;
		}if(a[i]=='7'){
			b[p++]=7;
		}if(a[i]=='6'){
			b[p++]=6;
		}if(a[i]=='5'){
			b[p++]=5;
		}if(a[i]=='4'){
			b[p++]=4;
		}if(a[i]=='3'){
			b[p++]=3;
		}if(a[i]=='2'){
			b[p++]=2;
		}if(a[i]=='1'){
			b[p++]=1;
		}
		if(a[i]=='0'){
			b[p++]=0;
		}
	}
	sort(b,b+p,cmp);
	for(int i=0;i<p;i++){
		cout<<b[i];
	}
	return 0;
} 
