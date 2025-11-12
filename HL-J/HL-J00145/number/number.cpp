#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int check_ch=0,check_num=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a'&&s[i]<='z')
			check_ch++;
		else
		{
			check_num++;
			a[check_num]=s[i]-'0';
		}
	}
	if(check_num==1)
	{
		cout<<a[1];
		return 0;
	}
	sort(a+1,a+check_num+1,cmp);
	for(int i=1;i<=check_num;i++)
		cout<<a[i];
	return 0;
}