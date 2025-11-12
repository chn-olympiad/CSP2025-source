#include<bits/stdc++.h>
using namespace std;
string a;
long long o=1,b[1000010],m=-999,d;
int main(){
	freopen("number.cpp","r",stdin);
	freopen("number.cpp","w",stdout);
	cin>>a;
	for(int i=1;i<=sizeof(a);i++){
		if ('0'<=a[i] && a[i]<='9'){
			b[o]=int(a[i])-48;
			o++;
		}
	}
	sort(b+1,b+1+o);
	for(int i=1;i<=o;i++){
		d=0;
		m=0;
		for(int j=1;j<=o;j++){
			if(b[j]>m){
				m=b[j];
				d=j;
			}
		} 
		b[d]=-1;
		cout<<m;
	}	
	return 0;
} 
