#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef double llf;
//-----------------------------
int n,Q,len;
struct chg
{
	string x,y;//chg x into y
}a[200020];

map<string,map<string,lld> >score;
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].x;
		cin>>a[i].y;
		++score[a[i].x][a[i].y];
	}
	while(Q--)
	{
		cin>>s1>>s2;
		len=s1.length();
		lld sum=0;
		for(int i=0;i<len;++i)
		{
			for(int j=i;j<len;++j)
			{
				string _a,_b1,_b2;
				for(int k=i;k<=j;++k)_b1+=s1[k];
				for(int k=i;k<=j;++k)_b2+=s2[k];
				chg kkk;
				kkk.x=_b1;
				kkk.y=_b2;
				if(score[kkk.x][kkk.y])
				{
					for(int k=0;k<i;++k)_a+=s1[k];
					_a+=_b2;
					for(int k=j+1;k<len;++k)_a+=s1[k];
					if(_a==s2)sum+=score[kkk.x][kkk.y];
				}
			}
		}
		cout<<sum<<endl;
	}
	//LQH保佑我~zr保佑我~
	fclose(stdin);
	fclose(stdout);
	return 0;
 }

