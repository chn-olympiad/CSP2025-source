#include<bits/stdc++.h>
using namespace std;
int b[1000010];
int n;
bool cmp(int&a,int&b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<(int)a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[n++]=a[i]-'0';
		}
	}
	sort(b,b+n,cmp);
	for(int i=0;i<n;i++){
		cout<<b[i];
	}
	return 0;
}