#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5,L=5e6+5,BASE=1331,MOD=1e9+7;
int n,q,tr[L][27],fail[L],flag[L],tot=1;
long long poww[L],ha[L],hatt;
struct uuu{
	string s,ss;
	long long ha;
}a[N];
string t,tt;
void insert(int id)
{
	int u=1;
	for(int i=0;i<a[id].s.length();i++)
	{
		int x=a[id].s[i]-'a';
		if(!tr[u][x]) tr[u][x]=++tot;
		u=tr[u][x];
	}
	flag[u]=id;
}
void build()
{
	for(int i=0;i<26;i++) tr[0][i]=1;
	queue <int> q;
	fail[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
//		cout<<u<<"\n";
//		system("pause");
		for(int i=0;i<26;i++)
		{
			if(tr[u][i])
			{
				fail[tr[u][i]]=tr[fail[u]][i];
				q.push(tr[u][i]);
			}else tr[u][i]=tr[fail[u]][i];
		}
	}
}
int cnt=0;
bool check(int pos,int id)
{
//	cout<<"CHECK!"<<pos<<" "<<id<<"\n";
	int r=pos,l=r-a[id].s.length()+1;
	long long cha=0;
	if(l==0) cha=((((a[id].ha*poww[l]%MOD)%MOD+ha[t.length()-1])%MOD-ha[r])%MOD+MOD)%MOD;
	cha=((((ha[l-1]+a[id].ha*poww[l]%MOD)%MOD+ha[t.length()-1])%MOD-ha[r])%MOD+MOD)%MOD;
//	cout<<l<<" "<<r<<" "<<cha<<" "<<hatt<<"\n";
	if(cha==hatt) return true;
	else return false;
}
void mat()
{
	int u=1;
	for(int i=0;i<t.length();i++)
	{
		u=tr[u][t[i]-'a'];
		int uu=u;
//		cout<<u<<"\n";
		while(uu)
		{
			if(flag[uu] && check(i,flag[uu])) cnt++;
			uu=fail[uu];
		}
	}
}
void init()
{
	poww[0]=1;
	for(int i=1;i<=5000000;i++) poww[i]=poww[i-1]*BASE%MOD;
}
long long geths(int id)
{
	long long sum=0;
	for(int i=0;i<a[id].ss.length();i++) sum=(sum+(a[id].ss[i]-'a')*poww[i]%MOD)%MOD;
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].ss;
		insert(i);
		a[i].ha=geths(i);
	}
	build();
	for(int i=1;i<=q;i++)
	{
		cnt=0;
		cin>>t>>tt;
		if(t.length()!=tt.length())
		{
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<t.length();j++)
		{
			if(j==0) ha[j]=(t[j]-'a')*poww[j]%MOD;
			else ha[j]=(ha[j-1]+(t[j]-'a')*poww[j]%MOD)%MOD;
		}
		hatt=0;
		for(int j=0;i<tt.length();j++) hatt=(hatt+(tt[j]-'a')*poww[j]%MOD)%MOD;
		mat();
		cout<<cnt<<"\n";
	}
}
