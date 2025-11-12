#include<bits/stdc++.h>
using namespace std;
#define int long long

string s;
priority_queue<int> q;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;int n=s.size();
	
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			q.push(s[i]-'0');

	if(q.top()==0) cout<<0;
	else
		while(!q.empty())
			cout<<q.top(),q.pop();
	
	return 0; 
}
//#Shang4Shan3Ruo6Shui4
