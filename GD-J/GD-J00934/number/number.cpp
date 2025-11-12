#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000],x=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[x]=int(s[i]-48);
			x++;
		}
	}
	if(a[1]>a[0]){
		int a1=a[1];
		a[1]=a[0];
		a[0]=a1;
	}
	for(int i=2;i<x;i++){
		if(a[i-1]<a[i]){
			long long w=a[i];
			a[i]=a[i-1];
			a[i-1]=w;
			i-=2;
		}
	}
	long long z=0;
	for(int i=0;i<x;i++){
		z*=10;
		z+=a[i];
	}
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
