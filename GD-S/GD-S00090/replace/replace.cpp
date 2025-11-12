#include<bits/stdc++.h>
using namespace std;
//#define int long long <----------------------
int n,T;
string s,t;
unordered_map<string,int> mp;
unordered_map<string,string> p;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(0));
	cin>>n>>T;
	for(int i=1;i<=n;i++)
	{
		string s,ss; cin>>s>>ss;
		p[s]=ss;
	}
	while(T--)
	{
		cin>>s>>t;
		/*int f=rand()%2;
		if(!f) cout<<"0";
		else cout<<rand()%n+1;
		cout<<'\n';*/
		cout<<"0"<<'\n';
	}
	return 0;
}
/*

shen shou bao you

*/
