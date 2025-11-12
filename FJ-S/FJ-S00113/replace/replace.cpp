#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fi first
#define se second
#define pii pair<int,int>
#define PII pair<pii,int>
using namespace std;
const int N=2e5+10;
int n,q,ms[N],m;
string s[N][2],t[2];
const ull b=12791;
map<pair<ull,ull> ,int> cnt;
ull Hx[2010][2010],Hy[2010][2010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		ull hx=0,hy=0;
		ms[i]=s[i][0].size();
		for(int j=0;j<ms[i];j++)
			hx=hx*b+(ull)s[i][0][j],
			hy=hy*b+(ull)s[i][1][j];
		cnt[make_pair(hx,hy)]++;
	}
	for(int i=1;i<=q;i++){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			printf("0\n");continue;
		}
		m=t[0].size();
		for(int j=0;j<m;j++){
			Hx[j][j]=(ull)t[0][j];
			Hy[j][j]=(ull)t[1][j];
			for(int k=j+1;k<m;k++)
				Hx[j][k]=Hx[j][k-1]*b+(ull)t[0][k],
				Hy[j][k]=Hy[j][k-1]*b+(ull)t[1][k];
		}
		ll ans=0;
		for(int j=0;j<m;j++){
			for(int k=m-1;k>=j;k--){
				ull hx=Hx[j][k],hy=Hy[j][k];
//					printf("%d %d %d : %lld %lld\n",i,j,k,(ll)hx,(ll)hy);
				ans+=(ll)cnt[make_pair(hx,hy)];
//					printf("%lld\n",ans);
				if(t[0][k]!=t[1][k]) break;
			}
			if(t[0][j]!=t[1][j]) break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

