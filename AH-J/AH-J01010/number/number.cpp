#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=1;
	for(int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9')
			a[x++]=s[i]-'0';
	}
	sort(a+1,a+x,cmp);
	for (int i=1;i<x;i++)
		cout<<a[i];
	return 0;
}
