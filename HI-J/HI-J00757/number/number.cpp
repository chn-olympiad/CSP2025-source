#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	priority_queue<int> maxHeap;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			maxHeap.push(s[i]-'0');
		}
	}
	while(!maxHeap.empty())
	{
		cout<<maxHeap.top();
		maxHeap.pop(); 
	}
} 
