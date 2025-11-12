#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	int len=s.size(),l=1;
	for (int i=0;i<len;i++){
		if (s[i]>='0'&&s[i]<='9'){
			a[l]=s[i]-'0';
			l++;
		} 
	}
	sort(a+1,a+l);
	for (int i=l-1;i>=1;i--) cout << a[i];
	return 0;
}

