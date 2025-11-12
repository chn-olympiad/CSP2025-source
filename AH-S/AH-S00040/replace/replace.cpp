#include <bits/stdc++.h>
using namespace std;
map<string,string>rp;
string strs[200050];
int n,q;
int pos;
string s1,s2;
string ans,askk;
string cutt(string inn,int startt,int endd)
{
	string outt;
	for(int i=startt;i<=endd;i++) outt=outt+inn[i];
	return outt;
}
long long think(string a,string b)
{
	long long res;
	int len,lenrule,cutstop;
	len=a.length();
	string temp;
	pos=0;
	for(int i=1;i<=n;i++)
	{
		pos=temp.find(strs[i]);
		if(pos==-1) continue;
		else 
		{
			lenrule=rp[strs[i]].length();
			cutstop=pos+lenrule;
			temp=cutt(a,0,pos-1)+rp[strs[i]]+cutt(a,cutstop,len-1);
			if(temp==b) res++;
		}
	}
	return res;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
		cin>>s1>>s2;
		rp.insert(make_pair(s1,s2));
		strs[i]=s1;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>askk>>ans;
		cout<<think(askk,ans)<<endl;
	}
    return 0;
}
