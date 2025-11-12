#include<iostream>
using namespace std;
int b[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9')
			b[a[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(b[i]--)
			cout<<i;
} 
