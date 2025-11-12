#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#define intt long long
#define intu unsigned long long
#define dle double
#define dlel long double
using namespace std;
const int Imax=0x7fffffff;
const long long LLmax=0x7fffffffffffffff;
const int N=1e5+5;
const int M=5e6+5;
int n,q;
string sa[N],sb[N];
string ss[N],st[N];
string s,t;
string a,b;
int cnt;
int l[N],r[N];
void change(int i)
{
	string &s=ss[i],&t=st[i];
	r[i]=s.size();
	reverse(s.begin(),s.end()),reverse(t.begin(),t.end());
	while(s.back()==t.back()) s.pop_back(),t.pop_back(),l[i]++;
	reverse(s.begin(),s.end()),reverse(t.begin(),t.end());
	while(s.back()==t.back()) s.pop_back(),t.pop_back(),r[i]--;
}
set<int> stt[N*2+5][2];
int findb(string s)
{
	int len=s.size();
	for(int i=0;i<len;i++) if(s[i]=='b') return i;
	return -1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>sa[i]>>sb[i];
		ss[i]=sa[i],st[i]=sb[i];
		change(i);
	}
	while(q--)
	{
		cin>>a>>b;
		s=a,t=b;
		reverse(s.begin(),s.end()),reverse(t.begin(),t.end());
		while(s.back()==t.back()) s.pop_back(),t.pop_back();
		reverse(s.begin(),s.end()),reverse(t.begin(),t.end());
		while(s.back()==t.back()) s.pop_back(),t.pop_back();
		int cnt=0,siz=s.size();
		for(int i=1;i<=n;i++)
		{
			if(siz!=ss[i].size()) continue;
			if(s==sa[i]&&t==sb[i]){cnt++;continue;}
			if(s==ss[i]&&t==st[i])
			{
				int len=sa[i].size();
				int flag=1;
				for(int j=0;j<l[i];j++)
				{
					if(a[j]!=sa[i][j])
					{
						flag=0;
						break;
					}
				}
				for(int j=r[i];j<len;j++)
				{
					if(a[j]!=sa[i][j])
					{
						flag=0;
						break;
					}
				}
				cnt+=flag;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
