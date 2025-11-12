#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5,M=5e6+5;
const LL MOD=1e9+7,base1=1331;
LL pw1[N],prea[N],preb[N];
LL ha[N],hb[N];
int n,qn,rk[N],len[N];
string sa[N],sb[N];
bool cmp(int x,int y){return len[x]<len[y];}
inline LL qa(int l,int r){
	LL res=(prea[r]-prea[l-1]*pw1[r-l+1]%MOD)%MOD;
	return (res+MOD)%MOD;
}
inline LL qb(int l,int r){
	LL res=(preb[r]-preb[l-1]*pw1[r-l+1]%MOD)%MOD;
	return (res+MOD)%MOD;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>qn;pw1[N]=1;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i],
		rk[i]=i,len[i]=sa[i].size();
		for(int j=0;j<len[i];j++){
			ha[i]=(ha[i]*base1+(int)(sa[i][j]))%MOD;
			hb[i]=(hb[i]*base1+(int)(sb[i][j]))%MOD;
		}
	}
	sort(rk+1,rk+1+n,cmp);
	while(qn--){
		string a,b;cin>>a>>b;
		int m=a.size();
		int ans=0;
		pw1[0]=1;
		for(int i=1;i<=m;i++)
			pw1[i]=pw1[i-1]*base1%MOD;
		for(int i=1;i<=m;i++){
			prea[i]=(prea[i-1]*base1+(int)(a[i-1]))%MOD;
			preb[i]=(preb[i-1]*base1+(int)(b[i-1]))%MOD;
		}
		int L=0,R=m+1;
		for(int i=1;i<=m;i++)
			if(!L&&a[i-1]!=b[i-1]){L=i;break;}
		for(int i=m;i>=1;i--)
			if(R==m+1&&a[i-1]!=b[i-1]){R=i;break;}
		int st=n+1;
		for(int rj=1;rj<=n;rj++)
			if(len[rk[rj]]>=R-L+1){st=rj;break;}
		for(int rj=st;rj<=n;rj++){
			int j=rk[rj];
			for(int i=R;i<=m&&i-len[j]+1<=L;i++)
				if(qa(i-len[j]+1,i)==ha[j]&&
					qb(i-len[j]+1,i)==hb[j])
					ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
