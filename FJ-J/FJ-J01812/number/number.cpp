#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int l;
bool cmp(char a,char b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
			l++;
		}
	}
	sort(a,a+1000005,cmp);
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
	return 0;
}
