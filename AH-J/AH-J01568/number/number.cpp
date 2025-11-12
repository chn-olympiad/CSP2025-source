
#include<bits/stdc++.h>
using namespace std;

string s;
int t[100],num;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	for(int i=0;i<int(s.size());i++)
		if(s[i]>='0' and s[i]<='9')
			t[int(s[i])]++,num++;
			
	if(t[int('0')]==num)
	{
		cout<<0;
		return 0;
	}

	for(int i=int('9');i>=int('0');i--)
		for(int j=0;j<t[i];j++)
			cout<<i-48;
	
	return 0;
}
