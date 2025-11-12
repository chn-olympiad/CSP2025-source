#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b[1000005],v=0;
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>=48&&a[i]<=57) b[++v]=a[i]-'0';
	}
	sort(b+1,b+v+1,cmp);
	for(int i=1;i<=v;i++){
		cout<<b[i];
	}
	return 0;
}
