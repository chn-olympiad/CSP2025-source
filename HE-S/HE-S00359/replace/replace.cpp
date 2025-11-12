#include<bits/stdc++.h>
using namespace std;
namespace code{
#define F(i,x,y) for(int i=x,__=y;i<=__;i++)
#define R(i,x,y) for(int i=y,__=x;i>=__;i--)
#define debug(x) cerr<<#x<<"="<<x<<endl
	using ll=long long;
	using uint=unsigned int;
	using ull=unsigned long long;
	struct mark{
		int x,y;
		constexpr mark(int a=0,int b=0):x(a),y(b){}
	};
	struct go{
		mark x,y;
		constexpr go(mark a,mark b):x(a),y(b){};
	};
	bool operator<(mark x,mark y){
		return (x.x==y.x)?(x.y<y.y):(x.x<y.x);
	}
	bool operator==(mark x,mark y){
		return x.x==y.x&&x.y==y.y;
	}
	bool operator<(go x,go y){
		return (x.x==y.x)?(x.y<y.y):(x.x<y.x);
	}
	const int N=200005,k1=221,k2=167,mod1=998244353,mod2=1000000009;
	int hash1(string x){
		ll s=0;
		for(auto i:x){
			s=(s*k1+i)%mod1;
		}
		return s;
	}
	int hash2(string x){
		ll s=0;
		for(auto i:x){
			s=(s*k2+i)%mod2;
		}
		return s;
	}
	map<go,int>ans;
	go ti(string t1,string t2){
		debug(t1);
		debug(t2);
		if(t1.length()!=t2.length())return go(mark(-1,-1),mark(-1,-1));
		int n=t1.length();
		t1=' '+t1;t2=' '+t2;
		string ans1,ans2;
		int re=0;
		F(i,1,n){
			if(t1[i]!=t2[i]){
				if(t1[i-1]==t2[i-1])re++;
				if(re>1)return go(mark(-1,-1),mark(-1,-1));
				ans1+=t1[i];
				ans2+=t2[i];
			}
		}
		return go(mark(hash1(ans1),hash2(ans1)),mark(hash1(ans2),hash2(ans2)));
	}
	int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin.tie(0)->sync_with_stdio(0);
		int n,q;
		cin>>n>>q;
		F(i,1,n){
			string x,y;
			cin>>x>>y;
			mark a(hash1(x),hash2(x)),b(hash1(y),hash2(y));
			ans[go(a,b)]++;
		}
		F(i,1,q){
			string t1,t2;
			cin>>t1>>t2;
			go yu(ti(t1,t2));
			if(yu.x.x==-1)cout<<0<<'\n';
			else cout<<ans[yu]<<'\n';
		}
		return 0;
	}
}
int main(){
	code::main();
	return 0;
}