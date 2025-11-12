#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
const int maxn=1e6+5;
string s;
int a[maxn],cnt=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0'){
			a[cnt]=s[i]-'0';
			cnt++;
//			cout<<a[i];
		}
	 } 
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
} 