#include<bits/stdc++.h>
using namespace std;

string s;
long long cnt[1000005];
long long a[15],pos,sum,st[10005];
vector<int> vt;
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			if(!a[s[i]-'0'])vt.push_back(s[i]-'0');
			a[s[i]-'0']=true;
			cnt[s[i]-'0']++;
			sum++;
		} 
	}
	sort(vt.begin(),vt.end(),cmp);
	for(int i=0;i<vt.size();i++)
	{
		for(int j=1;j<=cnt[vt[i]];j++)
		{
			cout<<vt[i];
		}
	}
	return 0;
}
