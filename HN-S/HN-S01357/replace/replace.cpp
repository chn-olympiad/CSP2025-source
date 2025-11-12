#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
using ll=long long;
#define File_IO 1
#define debug 0
int gcd(int a,int b)
{
	if(b)while((a%=b)&&(b%=a));
	return a+b;
}
void Ex_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		//1a+0=gcd(a,0)
		return;
	}
	Ex_gcd(b,a%b,y,x);
	y-=std::floor(a/b)*x;
	//b(x1)+(a-floor(a/b)*b)(y1)=gcd(a,b)
	//a(y1)+b(x1-floor(a/b)*y1)=gcd(a,b)
}
const int maxn=2e5+1,maxq=2e5+1;
vector<unsigned>solve_nxt(const string &s);
vector<unsigned>s_find(const string &s,const string &t,const vector<unsigned> &nxt);
struct str_pair
{
	string s_1,s_2;
	vector<unsigned>nxt_1,nxt_2;
	unsigned siz;
	void input()
	{
		cin>>s_1>>s_2;
		nxt_1=solve_nxt(s_1);
		nxt_2=solve_nxt(s_2);
		siz=s_1.size();
		if(siz!=s_2.size())
		{
			cerr<<"Input data Error!"<<endl;
			exit(-1);
		}
		#if debug
		cout<<"nxt "<<s_1<<endl;
		for(auto i:nxt_1)cout<<i<<' ';
		cout<<endl<<"nxt "<<s_2<<endl;
		for(auto i:nxt_2)cout<<i<<' ';
		cout<<endl;
		#endif
	}
}ti_huan[maxn];
int n,q;
string t_1,t_2;
vector<unsigned>p_1,p_2;
void solve()
{
	int wer=0;
	cin>>t_1>>t_2;
	for(int i=1;i<=n;i++)
	{
		const str_pair &tihuan=ti_huan[i];
		p_1=s_find(tihuan.s_1,t_1,tihuan.nxt_1);
		p_2=s_find(tihuan.s_2,t_2,tihuan.nxt_2);
		#if debug
		cout<<"p "<<tihuan.s_1<<" in "<<t_1<<endl;
		for(auto i:p_1)cout<<i<<' ';
		cout<<endl;
		cout<<"p "<<tihuan.s_2<<" in "<<t_2<<endl;
		for(auto i:p_2)cout<<i<<' ';
		cout<<endl;
		#endif
		string zzz=t_1;
		for(unsigned i1=0,i2=0;i1<p_1.size();i1++)
		{
			i2=lower_bound(p_2.begin(),p_2.end(),p_1[i1])-p_2.begin();
			if(i2<p_2.size()&&p_2[i2]==p_1[i1])
			{
				zzz=t_1;
				for(unsigned j=0;j<tihuan.siz;j++)
				{
					zzz[j+p_1[i1]-tihuan.siz+1]=tihuan.s_2[j];
				}
				#if debug
				cout<<"Tihuan:"<<endl;
				cout<<zzz<<' '<<t_2<<endl;
				#endif
				if(zzz==t_2)wer++;
				break;
			}
		}
	}
	cout<<wer<<endl;
}
int main()
{
	#if File_IO
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		ti_huan[i].input();
	}
	for(int i=1;i<=q;i++)
	{
		#if debug
		cout<<i<<endl;
		#endif
		solve();
	}
	return 0;
}
vector<unsigned>solve_nxt(const string &s)
{
	vector<unsigned>nxt;
	nxt.resize(s.size());
	nxt[0]=0;
	for(unsigned i=1,k=0;i<s.size();i++)
	{
		k=nxt[i-1];
		while(k!=0&&s[k]!=s[i])
		{
			k=nxt[k-1];
		}
		if(s[k]==s[i])nxt[i]=k+1;
		else nxt[i]=0;
	}
	return nxt;
}
vector<unsigned>s_find(const string &s,const string &t,const vector<unsigned> &nxt)
{
	vector<unsigned>wer;
	unsigned s_i=0,t_j=0;//Æ¥ÅäÁË¼¸¸ö×Ö·û 
	for(;t_j<t.size();t_j++)
	{
		while(s_i!=0&&s[s_i]!=t[t_j])
		{
			s_i=nxt[s_i-1];
		}
		if(s[s_i]==t[t_j])s_i++;
		if(s_i==s.size())
		{
			wer.push_back(t_j);
			s_i=0;
		}
	}
	return wer;
}
