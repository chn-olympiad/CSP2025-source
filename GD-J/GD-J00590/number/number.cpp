#include<bits/stdc++.h> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int a[1001005],sum=0;
string s;
bool cmp(int x,int y){
	if(x!=y)
		return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<=l-1;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++sum]=int(s[i]-'0');
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
		cout<<a[i];
	return 0;
}
