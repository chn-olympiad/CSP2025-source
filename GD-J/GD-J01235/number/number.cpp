#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		char ch=s[i];
		if (ch<='9' && ch>='0'){
			if(ch=='0')
				a[b++]=0;
			else if(ch=='1')
				a[b++]=1;
			else if(ch=='2')
				a[b++]=2;
			else if(ch=='3')
				a[b++]=3;
			else if(ch=='4')
				a[b++]=4;
			else if(ch=='5')
				a[b++]=5;
			else if(ch=='6')
				a[b++]=6;
			else if(ch=='7')
				a[b++]=7;
			else if(ch=='8')
				a[b++]=8;
			else if(ch=='9')
				a[b++]=9;
		}
	}
	sort(a,a+b);
	for (int i=b-1;i>=0;i--)
		cout<<a[i];
	return 0;
}
