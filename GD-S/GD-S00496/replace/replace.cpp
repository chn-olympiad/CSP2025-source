#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using VI=vector<int>;
using PII=pair<int,int>;
#define MP make_pair
#define fi first
#define se second
#define PB emplace_back
#define PPB pop_back
#define endl ('\n')
#define ALL(x) (x).begin(),(x).end()

const int N=200002,P=1e9+9,B2=0x6ECA11;
using ull=unsigned long long;
const ull B1=0x6ECA118627B;

int n,q;

struct hsh
{
	ull h1;
	int h2;
	bool operator==(const hsh &rhs)const{return h1==rhs.h1&&h2==rhs.h2;}
	bool operator!=(const hsh &rhs)const{return h1!=rhs.h1||h2!=rhs.h2;}
	bool operator<(const hsh &rhs)const{return h1<rhs.h1||h1==rhs.h1&&h2<rhs.h2;}
	hsh add(char ch)
	{return {h1*B2+ch,(1ll*h2*B2+ch)%P};}
};
hsh hs(string s)
{
	hsh x={0,0};
	for(char i:s)x=x.add(i);
	return x;
}

tuple<hsh,hsh,int,hsh,int,hsh> f[N];

int main() // 不会 T3 啊啊啊，只写了 50 pts 啊，这场是不是人均 AK 啊，要退役了啊啊啊 /ll
{
#ifndef LOCAL
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
#endif
	ios::sync_with_stdio(false),cin.tie(nullptr);

	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string S,T;
		cin>>S>>T;
		if(S==T)continue;
		string ft,bk;
		for(int j=0;j<S.size();j++)
			if(S[j]!=T[j]){ft=S.substr(0,j),S=S.substr(j),T=T.substr(j);break;}
		for(int j=S.size();j;j--)
			if(S[j-1]!=T[j-1]){bk=S.substr(j),S=S.substr(0,j),T=T.substr(0,j);break;}
		reverse(ALL(ft));
		f[i]={hs(S),hs(T),ft.size(),hs(ft),bk.size(),hs(bk)};
	}
	sort(f+1,f+n+1);

	while(q--)
	{
		string S,T;
		cin>>S>>T;
		string ft,bk;
		for(int j=0;j<S.size();j++)
			if(S[j]!=T[j]){ft=S.substr(0,j),S=S.substr(j),T=T.substr(j);break;}
		for(int j=S.size();j;j--)
			if(S[j-1]!=T[j-1]){bk=S.substr(j),S=S.substr(0,j),T=T.substr(0,j);break;}
	
		hsh cs=hs(S),ct=hs(T);
		vector<hsh> fs,bs;
		fs.PB(hsh{0,0}),bs=fs;

		for(int j=ft.size()-1;~j;j--)
			fs.PB(fs.back().add(ft[j]));
		for(int j=0;j<bk.size();j++)
			bs.PB(bs.back().add(bk[j]));
		int ans=0;
		for(auto it=lower_bound(f+1,f+n+1,make_tuple(cs,ct,0,fs[0],0,bs[0]));it!=f+n+1;it++)
		{
			auto [ss,tt,lh,hh,lb,bb]=*it;
			if(ss!=cs||tt!=ct)break;
			ans+=lh<=ft.size()&&hh==fs[lh]&&lb<=bk.size()&&bb==bs[lb];
		}
		cout<<ans<<endl;
	}

	return 0;
}