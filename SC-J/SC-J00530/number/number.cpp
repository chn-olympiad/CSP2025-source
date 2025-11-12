#include<bits/stdc++.h>
using namespace std;
string s;
int m=1;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i];
			m++;
		}
	for(int i=m;i>1;i--)
		for(int j=1;j<=i;j++)
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
	for(int i=1;i<=m;i++)
		cout<<a[i]; 
	return 0;
} 