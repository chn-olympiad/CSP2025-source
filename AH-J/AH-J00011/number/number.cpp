#include<bits/stdc++.h>
using namespace std;
char a[1000001];
char b[1000001];
string g;
int j=1;
int ls=0;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
getline(cin,g);
int x=g.size();
for(int i=0;i<x;i++){
	a[i]=(char)g[i];
}
while(x!=-1){
	if(a[x]>='1' && a[x]<='9'){
		b[j]=a[x];
		j++;
	}
	if(a[x]=='0'){
		ls++;
	}
	x--;
}
for(int i=0;i<j;i++){
	cout<<b[i];
}
while(ls--){
	cout<<"0";
}
return 0;
}
