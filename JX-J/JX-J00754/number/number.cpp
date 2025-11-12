#include<bits/stdc++.h>
using namespace std;
int b[1000001];
int c=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
for(int i=0;i<=a.size();i++){
	if(a[i]>='0'&&a[i]<='9')
	b[++c]=a[i]-'0';
}
sort(1+b,1+c+b,cmp);
for(int i=1;i<=c;i++){
	cout<<b[i];
}
return 0;
}
