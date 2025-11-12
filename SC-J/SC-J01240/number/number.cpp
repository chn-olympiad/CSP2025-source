#include<bits/stdc++.h>
using namespace std;
string a;
int num[100005],b=0,x=0;
int p(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9') num[b++]=a[i]-'0';
	}sort(num,num+b,p);
	for(int i=0;i<b;i++){
		x=x*10+num[i];
	}cout<<x;
	return 0;
}