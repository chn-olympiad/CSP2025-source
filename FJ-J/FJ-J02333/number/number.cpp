#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i];
			n++;
		}
	sort(a,a+n+1);
	for(int i=n;i>=1;i--) cout<<a[i];
	return 0;
} 
