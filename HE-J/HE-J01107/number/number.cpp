#include <bits/stdc++.h>
using namespace std;
const int N=1e6+200;

string s;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main ()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for (int i=0;i<l;i++){
		if (s[i]>='0'&&s[i]<='9'){
			a[i]=(int)(s[i]);
		}
	}
	sort(a,a+l,cmp);
	for (int i=0;i<l;i++){
		cout<<(char)(a[i]);
	}
	return 0;
}
