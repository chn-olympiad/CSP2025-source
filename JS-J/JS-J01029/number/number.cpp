#include<bits/stdc++.h>
using namespace std;
string s;
char n[1000000];
int a=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int m=s.size();
	for(int i=0;i<m;i++) {
		if(s[i]>=48&&s[i]<=57) {
			n[a]=s[i];
			a++;
		}
	}
	sort(n+1,n+a+1);
	for(int i=a;i>=1;i--) {
		cout<<n[i];
	}
	return 0;
}

