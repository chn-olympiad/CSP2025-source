#include<bits/stdc++.h>
using namespace std;
char s[10000001];
int a[10000001],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int w=1;
	while(cin>>s[w]){
		if(s[w]>='0'&&s[w]<='9') a[t++]=s[w]-'0';
		w++;
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=t;j++){
			if(s[i]<s[j]) swap(s[i],s[j]);
		}
	}
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
