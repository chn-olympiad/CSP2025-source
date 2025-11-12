#include<bits/stdc++.h> 
using namespace std;
#define pq priority_queue
#define mp map
#define mkp make_pair
#define ll long long
/*
feropen
number.ans
itn
mian
CCF
Genshin
y0
Never Gonna Give You UP~
guanzhu luogu@chenyuheng01 thank u miao~
put this in qipadaimadashang! I want to GO TV!
LOG:
[8:30]:start
[8:41]:T1 complete,start DEBUG
[9:30]:DEBUG complete(god d**med bug of map)
*/ 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string qwq; 
	string a;
	cin>>a;
	int n=a.size();
	mp<char,int> md;
	//cout<<n;
	for(int p=0;p<n;p++)
	{
		md[a[p]]++;
	}
	for(int i=9;i>=0;i--)
	{
		while(md[i+'0'])
		{
			//cout<<i;
			qwq+=(i+'0');
			md[i+'0']--;
		}
	}
	cout<<qwq;
	return 0;
}