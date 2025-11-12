#include <bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2="";
	freopen("number.in","r",stdin);
	cin>>s1;
	int ss1=s1.length();
	for(int i=0;i<ss1;i++){
		if(s1[i]>='0'&&s1[i]<='9')
			s2+=s1[i];
	}
	int ss2=s2.length();
	int a[ss2];
	for(int i=0;i<ss2;i++)
		a[i]=s2[i]-48;
	sort(a,a+ss2);
	freopen("number.out","w",stdout);
	for(int i=ss2-1;i>=0;i--)
		cout<<a[i];
	return 0;
}
