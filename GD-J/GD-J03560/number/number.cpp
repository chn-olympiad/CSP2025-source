#include<bits/stdc++.h>
using namespace std;
int n,m,t;
char a[1919810],c;
int cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if('0'<=c&&c<='9') a[++t]=c;
	}
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++) cout<<a[i];
	return 0;
}
