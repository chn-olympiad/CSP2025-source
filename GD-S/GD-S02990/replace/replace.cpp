#include<bits/stdc++.h>
#define uLL unsigned long long
#define N 200005
#define M 5000005
using namespace std;
int n,q;
string s[N][2],t[N][2];
uLL B(9901),pw[M],h[N][2],g[M][2];
inline uLL CCF(int x,int l,int r){
	return g[r][x]-(l?g[l-1][x]*pw[r-l+1]:0);
}
vector <array <int,4> > F[M<<1];
long long ANS[N];
int c[M],MM;
inline int lowbit(int x){return x&-x;}
inline void Add(int x,int y){
	while(x<=MM){
		c[x]+=y;
		x+=lowbit(x);
	}
}
inline int Sum(int x){
	int sum(0);
	while(x){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;for(int i(1);i<M;++i) pw[i]=pw[i-1]*B;
	scanf("%d%d",&n,&q);
	for(int i(1);i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		for(int j(0);j<s[i][0].size();++j){
			h[i][0]=h[i][0]*B+s[i][0][j];
			h[i][1]=h[i][1]*B+s[i][1][j];
		}
	}
	int LEN(0);
	for(int i(1);i<=q;++i){
		cin>>t[i][0]>>t[i][1];
		LEN+=t[i][0].size();
	}
	if(n<=1000&&LEN<=2000){
		for(int i(1);i<=q;++i){
			int k1,k2;
			for(int j(0);j<t[i][0].size();++j)
				if(t[i][0][j]!=t[i][1][j])
				{k1=j;break;}
			for(int j(t[i][0].size()-1);~j;--j)
				if(t[i][0][j]!=t[i][1][j])
				{k2=j;break;}
			for(int j(0);j<t[i][0].size();++j){
				g[j][0]=(j?g[j-1][0]*B:0)+t[i][0][j];
				g[j][1]=(j?g[j-1][1]*B:0)+t[i][1][j];
			}
			int ans(0);
			for(int j(1);j<=n;++j){
				if(s[j][0].size()<k2-k1+1) continue;
				for(int k(s[j][0].size()-1);k<t[i][0].size();++k){
					if(k-s[j][0].size()+1<=k1&&k>=k2
					&&CCF(0,k-s[j][0].size()+1,k)==h[j][0]
					&&CCF(1,k-s[j][0].size()+1,k)==h[j][1]){
						++ans;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	else{
		MM=0;
		for(int i(1);i<=n;++i){
			int x,y;
			for(int j(0);j<s[i][0].size();++j)
				if(s[i][0][j]=='b')
				{x=j;break;}
			for(int j(0);j<s[i][1].size();++j)
				if(s[i][1][j]=='b')
				{y=j;break;}
			F[x-y+M].push_back({x,(int)s[i][0].size()-x,i,1});
			MM=max(MM,(int)s[i][0].size()-x);
		}
		for(int i(1);i<=q;++i){
			int x,y;
			for(int j(0);j<t[i][0].size();++j)
				if(t[i][0][j]=='b')
				{x=j;break;}
			for(int j(0);j<t[i][1].size();++j)
				if(t[i][1][j]=='b')
				{y=j;break;}
			F[x-y+M].push_back({x,(int)t[i][0].size()-x,i,0});
			MM=max(MM,(int)t[i][0].size()-x);
		}
		for(int i(0);i<(M<<1);++i){
			sort(F[i].begin(),F[i].end());
			for(auto K:F[i]){
				if(K[3]) Add(K[1],1);
				else ANS[K[2]]=Sum(K[1]);
			}
			for(auto K:F[i]){
				if(K[3]) Add(K[1],-1);
			}
		}
		for(int i(1);i<=q;++i) printf("%lld\n",ANS[i]);
	}
	return 0;
}
