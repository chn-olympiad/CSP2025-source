#include<bits/stdc++.h>
#define pll pair<long long,long long>
#define f(a) a.first
#define s(a) a.second
using ll=long long;
using namespace std;
/*
哈希
最好双模 
给了2048的空间，不就是让我们放心开ll 5e6吗？！ 
可能是时间有问题，样例过了是过了，但是时间好像有点长...... 
*/

const ll mo = 1e9+7, p = 818233;
const ll moo = 998770103, pp = 11451;

bool f[200005];//两个二元组是否相同 
ll P[5000006], PP[5000006];
string t[3];
string s[200005][3];
ll h[3][5000006], hh[3][5000006];
//h[1] 是t1的第一个模数哈希，h2是第二个 
pll sh[200005][3];
//sh[k][1] = {a,b} 是s[k][1]的双模数哈希 

void jian_hash(int k)
{
	int l = s[k][1].size(); 
	pll ha = {0,0}, haa = {0,0};
	for(int i = 0;i < l;i++)
	{
		f(ha)=f(ha)*p%mo+(ll)s[k][1][i];
		s(ha)=s(ha)*pp%moo+(ll)s[k][1][i];
		
		f(haa)=f(haa)*p%mo+(ll)s[k][2][i];
		s(haa)=s(haa)*pp%moo+(ll)s[k][2][i];
	}
	sh[k][1]=ha;sh[k][2]=haa;
	if(ha == haa)f[k]=1;
	return ;
}

void pre_P()
{
	PP[0] = P[0] = 1;
	for(int i = 1;i <= 5000000;i++)
	{
		P[i] = P[i-1]*p%mo;
		PP[i] = PP[i-1]*pp%moo;
	}
	return ;
}

void pre_hash()
{
	int l = t[1].size(); 
	pll ha = {0,0}, haa = {0,0};
	for(int i = 0;i < l;i++)
	{
		h[1][i]=f(ha)*p%mo+(ll)t[1][i];
		h[2][i]=s(ha)*pp%moo+(ll)t[1][i];
		hh[1][i]=f(haa)*p%mo+(ll)t[2][i];
		hh[2][i]=s(haa)*pp%moo+(ll)t[2][i];
		ha={h[1][i],h[2][i]};
		haa={hh[1][i],hh[2][i]};
	}
	//cout << f(ha) <<" " << s(ha)<<"\n"<< f(haa)<<" "<< s(haa) <<"\n\n";
	return ;
}

pll query(pll a,pll b,ll cha)
//a 前面的哈希值 b 后面的哈希值 cha 它们两个的位置差，也就是长度 
{
	ll x = (f(b)-f(a)*P[cha]%mo+mo)%mo;
	ll y = (s(b)-s(a)*PP[cha]%moo+moo)%moo;
	return {x,y};
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//pll mm = {1,2};printf("%d %d\n",f(mm),s(mm));
	ios::sync_with_stdio(0);cin.tie(0);
	int n, q;
	cin >> n >> q; 
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i][1] >> s[i][2]; 
		jian_hash(i);
		//cout<<f(sh[i][1])<<" "<< s(sh[i][1])<<"\n"<<f(sh[i][2])<<" "<<s(sh[i][2])<<"\n\n"; 
	}
	pre_P();
	while(q--)
	{
		cin >> t[1] >> t[2];
		pre_hash();
		int lt = t[1].size();
		int l = -1, r;
		ll ans = 0;
		for(int i = 0;i < lt;i++)
		{
			if(l == -1&&t[1][i] != t[2][i])l=i;
			if(t[1][i] != t[2][i])r = i;
		} 
		//cout << l <<","<<r<<"\n";
		if(l == -1)//全都相同
		{
			for(int i = 1;i <= n;i++)
			{
				if(f[i])
				{
					int L = s[i][0].size();
					for(int j = 0;j < lt-L+1;j++)
					{
						int k = j+L-1;
						if(query({h[1][j],h[2][j]},{h[1][k],h[2][k]},L) == sh[i][1])
						ans++;
					}
				}
			} 
			cout << ans <<"\n";
			continue;
		} 
		for(int i = 1;i <= n;i++)
		{
			int L = s[i][1].size();
			if(L < r-l+1||f[i])continue;
			for(int j = max(r-L+1,0);j <= l&&j < lt-L+1;j++)
			{
				int k = j+L-1;
				pll qian={0,0};
				if(j>0)qian = {h[1][j-1],h[2][j-1]};
				auto qq=query(qian,{h[1][k],h[2][k]},L);
				//cout << j<<"~"<<k<<" "<<f(qq)<<" "<<s(qq)<<"\n"; 
				if(query(qian,{h[1][k],h[2][k]},L) == sh[i][1])
				{
					if(j > 0)qian={hh[1][j-1],hh[2][j-1]};
					if(query(qian,{hh[1][k],hh[2][k]},L) == sh[i][2])
					ans++;
				}
			}
		}
		cout << ans <<"\n";
	} 
	return 0;
} 
