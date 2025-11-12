#include<bits/stdc++.h>
using namespace std;
int a[10000009],n,s,i;
char ch;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>ch){
		if(ch>='0'&&ch<='9'){
			s++;
			a[s]=ch-'0';
		}
	}
	sort(a+1,a+1+s);
	for(i=s;i>=1;i--)cout<<a[i];
	return 0;
}
