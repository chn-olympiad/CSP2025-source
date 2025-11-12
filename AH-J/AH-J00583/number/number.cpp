#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//string s;
	char s[1000005];
	int l,x=0,a[1000005];
	cin>>s;
	l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[++x]=s[i]-48;
	}
	/*for(int i=1;i<x;i++){
		for(int j=i+1;j<=x;j++){
			if(a[j]>a[i]) swap(a[i],a[j]);
		}
	}*/
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--)
		cout<<a[i];
	return 0;
}
