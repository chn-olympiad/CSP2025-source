#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

const int N=1e7+10;
string st;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	vector<int> a;
	int sum=0;
	cin>>st;
	
	for(int i=0;i<(int)(st.size());i++)
	{
		if((st[i]-'0')>=0&&(st[i]-'0')<=9)
			a.push_back(st[i]-'0'),sum++;
	}
	
	sort(a.begin(),a.end(),cmp);
	if(a[0]==0)
		return cout<<0,0;
	
	for(int i=0;i<sum;i++)cout<<a[i];
	return 0;
}
