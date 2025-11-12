#include<bits/stdc++.h>
using namespace std;
struct sth//支持全体 xor，插入一个数，查询 
{
	set<int> st;
	int xor_num;
	inline void xor_all(int x)
	{
		xor_num^=x;
	}
	bool have_it(int x)
	{
		x^=xor_num;
		return st.find(x)!=st.end();
	}
	void add(int x)
	{
		x^=xor_num;
		st.insert(x);
	}
	void clear()
	{
		st.clear();
		xor_num=0;
	}
}p;
int main()
{
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int n,k;cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		p.xor_all(x);
		p.add(x);
		if(p.have_it(k))
		{
			ans++,p.clear();
		}
	}
	cout<<ans<<'\n';
}
/*
   -----+------++-
  --------------
    ------------
  ---+---+---+----                   // +++ 这招太狠了 
  ---   ---    -+--
    -+- --- --- 
      ---  -+-
        -+-
______________________________
*/

/*
             1000
             combo
                _____
          /    /     \
         /     |      \
         \     |       |
          \    |      /
           \___+_____/
               |
               |
               |
               |




       Fantastic clear!
*/
//Later
//哎我怎么还不会，倒闭了
//9:41,原来我是奶龙，现在会了 
//anke2017 如是说。
//ODT,ODT，悄悄地放在出题人的后面，大家不要告诉他！快点快点 AC 啦，快点快点 AC 啦，快点快点 AC 啦。
 
