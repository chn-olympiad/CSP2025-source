#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int p=1;
	string s;char a[1000001];
	cin>>s;
	for(int i=0;i<=s.size();i++)
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[p]=s[i];
			p++;
		}
	sort(a+1,a+1+p);
		for(int i=p;i>0;i--)
		cout<<a[i];
	return 0;
}
