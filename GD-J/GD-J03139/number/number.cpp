#include<bits/stdc++.h>
using namespace std;
const int n=1e7+10;
bool cmp(int a,int b){
	return a>b;
}
string a;
int b[n],j=0;
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long l=a.length();
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++j]=a[i]-48;
		}
	}sort(b+1,b+j+1,cmp);
	for(int i=1;i<=j;i++){
		cout<<b[i];
	}
	return 0;
}
