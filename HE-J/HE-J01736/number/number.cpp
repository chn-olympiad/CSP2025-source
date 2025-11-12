#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000005],sum;
inline void print(int n)
{
	if(n<0) putchar('-'),n=-n;
	if(n>9) print(n);
	putchar(n%10+'0');
}
bool cmp(int a,int b){  return a>b;  }
int32_t main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int slen=s.size();
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			sum++;
		}
	sort(a,a+slen,cmp);
	for(int i=0;i<=sum-1;i++) print(a[i]);
	return 0;
}
