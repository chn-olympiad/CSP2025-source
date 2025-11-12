#include<bits/stdc++.h>
using namespace std;
int n,t=0,i;string s;char a[1000005];
int main(){//number
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.size();
	for(i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')a[t++]=s[i];
	}
	sort(a,a+t,greater<char>());
	for(i=0;i<t;i++)cout<<a[i];
}
