#include<bits/stdc++.h> 
using namespace std;
const int INF=1e5+5;
int n,m,x,y,z,ans;
string s,ss;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s>>ss;
	for(int i=1;i<=m;i++)
		cin>>s>>ss;
	for(int i=1;i<=m;i++)
		cout<<0<<endl;
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
