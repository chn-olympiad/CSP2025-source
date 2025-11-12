#include<bits/stdc++.h>
using namespace std;
string s;int a[1000090],j=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if('0'<=s[i] && '9'>=s[i])
		{
			j++;
			a[j]=s[i]-'0';
			
		}
		
	}
	sort(a+1,a+s.size()+1,cmp);
	for(int i=1;i<=j;i++)
	{
		cout<<a[i];
	}
	return 0;
}
