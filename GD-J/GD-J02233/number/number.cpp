#include <bits/stdc++.h>
#define N 1000005
using namespace std;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=0,l=s.size();
	for(int i=0;i<l;i++)
		if(isdigit(s[i]))a[++n]=s[i]-'0';
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)printf("%d",a[i]);
	return 0; 
}
