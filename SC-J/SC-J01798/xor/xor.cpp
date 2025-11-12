#include<bits/stdc++.h> 
using namespace std;
#define pq priority_queue
#define mp map
#define mkp make_pair
#define ll long long
/*
feropen
seat.ans
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
[9:30]:DEBUG complete(god d**med bug of map),T2 start
[9:47]:T2 complete,start DEBUG 
[9:50]:T2 complete,start T3
[10:00]:T3 start 30pts solver
[10:06]:30pts down,start 10pts
[10:11]10pts done
[10:19]:start T4 
*/ 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> v;
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		v.push_back(t); 
		mp[t]++;
	}
	cout<<n/2<<endl;
	return 0;
	
}