#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010],o=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
	if(a[i]>='0'&&a[i]<='9'){
	b[o]=(int)a[i]-48;
	o++;}}
	sort(b,b+o);
	for(int i=o-1;i>=0;i--)cout<<b[i];
}
