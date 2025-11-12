#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
string s;
priority_queue<int> q;
int cnt=0;
int main()
{	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
	{	if(s[i]<='9'&&s[i]>='0')
			q.push(s[i]-48),cnt++;
	}
	for(int i=0;i<cnt;i++)
	{	cout<<q.top();
		q.pop(); 
	}
	cout<<"\n";
	return 0;
}
//DeBruyne rp++
