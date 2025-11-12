#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string in;
	int nums[10]={0};
	cin>>in;
	for(char c:in)
	{
		if(c>='0'&&c<='9') nums[c-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<nums[i];j++) cout<<i;
	}
	return 0;
}
