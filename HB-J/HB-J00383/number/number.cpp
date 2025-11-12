#include <bits/stdc++.h>
using namespace std;
string a,b = "";
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int slen = a.size();
	for(int i = 0;i < slen;i ++){
		if(a[i] >= '0' && a[i] <= '9')b += a[i] ;
	}
	int len = b.size();
	for(int i = 0;i < len;i ++)
		for(int j = i + 1;j < len;j ++)
			if(b[i] < b[j])swap(b[i] , b[j]);
	cout << b;
	return 0;
}
