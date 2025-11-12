#include<bits/stdc++.h>
using namespace std;
string a;
int b=0;
int n[100009];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	for(int i=0;i<a.size();i++){
		if(a[i]>=48&&a[i]<=57){
			n[i]=a[i];
			b++;
		}
	}
	sort(n+0,n+a.size(),cmp);
	for(int i=0;i<b;i++){
		cout<<char(n[i]);
	} 
	return 0;
}
