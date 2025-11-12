#include <bits/stdc++.h>
using namespace std;

bool kx(int &a , int &b){
	if(a<b){
		return a>b;
	}
}
int a[1000002];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int count=0;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			a[count]=0;
			count++;
		}
		if(s[i]=='1'){
			a[count]=1;
			count++;
		}
		if(s[i]=='2'){
			a[count]=2;
			count++;
		}
		if(s[i]=='3'){
			a[count]=3;
			count++;
		}
		if(s[i]=='4'){
			a[count]=4;
			count++;
		}
		if(s[i]=='5'){
			a[count]=5;
			count++;
		}
		if(s[i]=='6'){
			a[count]=6;
			count++;
		}
		if(s[i]=='7'){
			a[count]=7;
			count++;
		}
		if(s[i]=='8'){
			a[count]=8;
			count++;
		}
		if(s[i]=='9'){
			a[count]=9;
			count++;
		}
	}
	sort(a,a+100001,kx);
	for(int i=0;i<1000001;i++){
		if(a[i]!=0){
			cout<<a[i];
		}
	}
	return 0;
}
