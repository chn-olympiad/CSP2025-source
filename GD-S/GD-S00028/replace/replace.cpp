#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1,s2;
map<string,int>mp;
signed main(){
	//feropen()
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>s1>>s2;
		int len=s1.size();
		int L=0,R=len-1;
		string st1="",st2="";
		while(L<=R&&(s1[L]==s2[L]||s1[R]==s2[R]))
		{
			if(s1[L]==s2[L])L++;
			if(s1[R]==s2[R])R--;
		}
		for(int i=L; i<=R; i++)
			st1=st1+s1[i],st2=st2+s2[i];
		mp[st1+'&'+st2]++;
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		int len=t1.size();
		int L=0,R=len-1;
		string st1="",st2="";
		while(L<=R&&(t1[L]==t2[L]||t1[R]==t2[R]))
		{
			if(t1[L]==t2[L])L++;
			if(t1[R]==t2[R])R--;
		}
		for(int i=L; i<=R; i++)
			st1=st1+t1[i],st2=st2+t2[i];
		cout<<mp[st1+'&'+st2]<<'\n';
	}
	return 0;
}
