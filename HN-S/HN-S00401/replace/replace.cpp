#include <bits/stdc++.h> 

/*
I want to be shown up on the curious code list.
But I am grade 10 and my English level can't reach the orderinary level.
So I will just say something.

1. The best case is to AFO this year.
2. It seems that I can only AC 2 problems at most and I have no ideas to pianfen(maybe).
3. I want to get World Vanquisher [ftr] PM,but I just get 1-1.
4. I want to get Stasis [ftr] PM,but I just get 1-2.
5. Who can teach me play any PvP games.
*/

namespace solve
{
	int n,q;
	struct hash
	{
		constexpr static unsigned long long k=37;
		constexpr static unsigned p1=998244353,p2=1000000007;
		unsigned len,h1,h2;
		hash(){len=h1=h2=0;}
		hash(unsigned len,unsigned long long h1,unsigned long long h2):len(len),h1(h1),h2(h2){}
		friend bool operator<(const hash& a,const hash& b)
		{
			return
				a.len!=b.len?a.len<b.len:
					a.h1!=b.h1?a.h1<b.h1:
						a.h2<b.h2;
		}
		hash operator+(const char c){return {len+1,(h1*k+c-(unsigned long long)('a'-1))%p1,(h2*k+c-(unsigned long long)('a'-1))%p2};}
	};
	std::map<std::pair<hash,hash>,std::vector<std::pair<hash,hash>>> s;
	void main()
	{
		std::cin>>n>>q;
		for(int i=0;i<n;i++)
		{
			std::string s1,s2;
			std::cin>>s1>>s2;
			int l=0,r=s1.size()-1;
			hash pre,suf,a,b;
			for(;s1[l]==s2[l];l++);
			for(;s1[r]==s2[r];r--);
			for(int i=l;i<=r;i++) a=a+s1[i],b=b+s2[i];
			for(l--;l>=0;l--) pre=pre+s1[l];
			for(r++;r<s1.size();r++) suf=suf+s1[r];
			s[{a,b}].push_back({pre,suf});
		}
		while(q--)
		{
			std::string t1,t2;
			std::cin>>t1>>t2;
			if(t1.size()!=t2.size())
			{
				std::cout<<"0\n";
				continue;
			}
			int l=0,r=t1.size()-1;
			hash a,b;
			for(;t1[l]==t2[l];l++);
			for(;t1[r]==t2[r];r--);
			for(int i=l;i<=r;i++) a=a+t1[i],b=b+t2[i];
			std::vector<std::pair<hash,hash>>& t=s[{a,b}];
			std::set<hash> pre{hash()},suf{hash()};
			l--,r++;
//			continue;
			for(hash tpre;l>=0;l--)
			{
				tpre=tpre+t1[l];
				pre.insert(tpre);
			}
			for(hash tsuf;r<t1.size();r++)
			{
				tsuf=tsuf+t1[r];
				suf.insert(tsuf);
			}
			int ans=0;
			for(auto p:t)
				if(pre.count(p.first)&&suf.count(p.second))
					ans++;
			std::cout<<ans<<'\n';
		}
	}
}

int main()
{
#define PROBLEM_STLVECTOR "replace"
#if 1
	freopen(PROBLEM_STLVECTOR".in","r",stdin);
	freopen(PROBLEM_STLVECTOR".out","w",stdout);
#endif
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve::main();
	return 0;
}
