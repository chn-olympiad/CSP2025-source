#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
//isdigit('1') 1
char ch[N];

bool cmp(char a,char b)
{
	return a>b;
}

int main()//1.freopen 2.cin 3.cout 4.
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	//shang	mian jian cha yaaa!!!
	
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i]))
		{
			j++;
			ch[j]=s[i];
		}
	sort(ch+1,ch+j+1,cmp);
	for(int i=1;i<=j;i++)
	{
		cout<<ch[i];
	}
	return 0;
}
