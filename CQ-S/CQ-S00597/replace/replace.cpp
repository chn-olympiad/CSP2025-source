/*
啥啊，只会暴力，不过A性质好像也能过
其实B性质搞搞疑似也能过 
1~8+13~14
随机数据其实也还好 
*/
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int N = 2e5+10,M = 5e6+10,V = 5e6,L = 1e9,P = 55311711,O = 1e7;
const ll mod1 = 1e9+1,mod = 998442353,B1 = 2331,B = 114517;
int n,q,tr[M*2][26],S[M*2],root[M*2],cnt = N,l,r,len,len1,cnt1,cnt5,ly;
ll dw,dw1,dw2,dw3,ans;
int v[P+10],v2[P+10],o,o1,o2,o3,sum;
bool v1[P+10];
string s,s1;
map<pair<ll,ll>,int>mp,mp1;
int mpcnt,mpcnt1,x,y,z;
string Tr,Tr1;
int Tcnt,Tcnt1;
inline void insert(int x)
{
	for(int i = 0;i < Tcnt;i++)
	{
		y = Tr[i]-'a';
		if(!tr[x][y]) tr[x][y] = ++cnt; 
		x = tr[x][y];
	} S[x]++;//S_i表示根到这里有几个点
}//我们把前n个让出来给这里的 
inline int insert1(int x)
{
	for(int i = 0;i < Tcnt;i++)
	{
		y = Tr[i]-'a';
		if(!tr[x][y]) tr[x][y] = ++cnt,root[cnt] = cnt+1,cnt++; 
		x = tr[x][y];
	}
	return x;
}
inline void query2(int x)
{//fu为那个R+1~n的离散值 
	for(int i = 0;i < Tcnt1;i++)
	{
		ans += S[x];
		y = Tr1[i]-'a';
		if(!tr[x][y]) return;
		x = tr[x][y];
	}// if(ly == 101) cout<<S[x]<<" "<<x<<'\n';
	ans += S[x];
}
inline void query(int x)
{//fu为那个R+1~n的离散值 
	for(int i = 0;i < Tcnt;i++)
	{
		query2(root[x]);
		y = Tr[i]-'a';
		if(!tr[x][y]) return;//不可能还有了
		x = tr[x][y];
	}
	//if(ly == 101) cout<<x<<'\n';
	query2(root[x]);
}
signed main()
{//输入5e6量级竟然没有快读，太恐怖了 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	//std::mt19937 rnd(time(0));
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{ 
		cin >> s >> s1;
		len = s.size();
		l = len+1,r = -1;
		for(int j = 0;j < len;j++)
			if(s[j] != s1[j])
			{
				if(l == len+1) l = j;
				r = j;
			}
		if(l == len+1) continue;//没用，因为完全相同了
		dw = dw1 = 0;
		dw2 = dw3 = 0;
		for(int j = l;j <= r;j++)
		{
			dw = (dw*B+(s[j]-'a'+1))%mod,dw1 = (dw1*B1+(s[j]-'a'+1))%mod1;
			dw2 = (dw2*B+(s1[j]-'a'+1))%mod,dw3 = (dw3*B1+(s1[j]-'a'+1))%mod1;
		}
		if(!mp[make_pair(dw*L+dw1,dw2*L+dw3)]) mp[make_pair(dw*L+dw1,dw2*L+dw3)] = ++mpcnt,root[mpcnt] = ++cnt;//新建一个节点
		o = mp[make_pair(dw*L+dw1,dw2*L+dw3)];
		Tcnt = 0; Tr = "";
		for(int j = l-1;j >= 0;j--) Tr += s[j],Tcnt++;
		o1 = insert1(o);
		Tcnt = 0; Tr = "";
		for(int j = r+1;j < len;j++) Tr += s[j],Tcnt++;
		insert(root[o1]);//插入
	}
	while(q--)
	{// ly++;
		cin >> s >> s1;
		len = s.size(),len1 = s1.size();
		if(len != len1)//没说想不想等 
		{
			cout<<0<<'\n';
			continue;
		}
		l = len+1,r = -1;
		for(int j = 0;j < len;j++)
			if(s[j] != s1[j])
			{
				if(l == len+1) l = j;
				r = j;
			}
		if(l == len+1)
		{
			cout<<0<<'\n';
			continue;
		}
		dw = dw1 = 0;
		dw2 = dw3 = 0;
		for(int j = l;j <= r;j++)
		{
			dw = (dw*B+(s[j]-'a'+1))%mod,dw1 = (dw1*B1+(s[j]-'a'+1))%mod1;
			dw2 = (dw2*B+(s1[j]-'a'+1))%mod,dw3 = (dw3*B1+(s1[j]-'a'+1))%mod1;
		}
		o = mp[make_pair(dw*L+dw1,dw2*L+dw3)];
		if(!o)//没有 
		{
			cout<<0<<'\n';
			continue;
		} ans = 0;
		Tcnt = 0; Tr = "";
		for(int j = l-1;j >= 0;j--) Tr += s[j],Tcnt++;
		Tcnt1 = 0; Tr1 = "";
		for(int j = r+1;j < len;j++) Tr1 += s[j],Tcnt1++; 
		query(o);
		cout<<ans<<'\n';
	}
	//保证t,t1是不相同的 
	return 0; 
}
/*
题目大致再说，有n种替换方式（也许可以相等）表示S_{i,1}可以变为S_{i,2}
然后q次询问，每次给出T,T1，可以从T中找一个子串（连续）替换为S_{i,2}（如果S_{i,1}等于这个子串的话）
求方案数，方案不同当且仅当拿的子串不同或二元组不同
map存一下，朴素暴力可以做到qn^2log
或者说是L2^2log
一般性的，我们先求出不合法的区间L,R（即左右端点必须在其左右或其端点处）
然后考虑枚举l的位置，然后我们考虑看那些二元组满足：
S_{1,R-l+1} = T_{l,R}
S1_{1,R-l+1} = T1_{l,R}
然后求满足这个条件的S_{R-l+2,R-l+1+o} = S1_{R-l+2,R-l+1+o} = T_{R+1,R+o}的个数 
事实上，每个二元组S也可以去找一段区间L_i,R_i，然后这是最小的包含所有不相等的区间
那么显然需要L_i=L,R_i=R时，这个二元组才有概率生效
考虑hash，对于区间(L,R)求出所有二元组L_i,R_i的是这个区间的，然后左边一段有相等，右边一段有相等的个数
也就是左边是(1,L-1)的后缀，右边是(R+1,n)的前缀
考虑枚举左端点，然后右边本质上是trie树上一条链的1值，我们可以直接取
然后就好了，空间2048mb应该是完全能开的
复杂度大致预估是Vlog的，因为离散化，其实可以hash表存 
*/
