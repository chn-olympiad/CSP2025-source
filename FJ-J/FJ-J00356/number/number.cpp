#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b="";
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9')b+=a[i];
	}
	int c[b.size()];
	for(int i=0;i<b.size();i++){
		c[i]=b[i]-48;
	}
	sort(c,c+b.size());
	if(c[b.size()-1]==0)cout<<0;
	else for(long long i=b.size()-1;i>=0;i--)cout<<c[i];
	return 0;
} 
