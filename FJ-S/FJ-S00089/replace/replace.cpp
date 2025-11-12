#include <bits/stdc++.h>
#define str string
#define ll long long
#define pii pair<ll,ll>
#define mkp make_pair
using namespace std;

const int MAXN=2e5+5;
const ll MOD=1e9+7;
const ll base=27;

ll s[MAXN][2];
str t[2],tmp[2];
ll a[2];
int n,q;
int len=0;
int l,r;
map<pii,int> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>t[0]>>t[1];
		len=t[0].length();
		for(int j=0;j<len;++j)
			s[i][0]=(s[i][0]*base+t[0][j]-'a'+1)%MOD,
			s[i][1]=(s[i][1]*base+t[1][j]-'a'+1)%MOD;
		if(mp.find(mkp(s[i][0],s[i][1]))!=mp.end()) mp[mkp(s[i][0],s[i][1])]++;
		else mp[mkp(s[i][0],s[i][1])]=1;
	}
	while(q--){
		cin>>t[0]>>t[1];
		len=t[0].length();
		if(len!=t[1].length()){
			printf("0\n");
			continue;
		}
		l=-1;
		for(int i=0;i<len;++i)
			if(t[0][i]!=t[1][i]){
				l=i;
				break;
			}
		int cnt=0;
		if(l==-1){
			for(int i=0;i<len;++i){
				a[0]=a[1]=0;
				for(int j=i;j<len;++j){
					a[0]=(a[0]*base+t[0][j]-'a'+1)%MOD,a[1]=(a[1]*base+t[1][j]-'a'+1)%MOD;
					if(mp.find(mkp(a[0],a[1]))!=mp.end()) cnt+=mp[mkp(a[0],a[1])];
				}
			}
			printf("%d\n",cnt);
			continue;
		}
		for(int i=len-1;i>=0;--i)
			if(t[0][i]!=t[1][i]){
				r=i;
				break;
			}
//		printf("[%d %d]\n",l,r);
		for(int i=0;i<=l;++i){
			a[0]=a[1]=0;
			for(int j=i;j<r;++j) a[0]=(a[0]*base+t[0][j]-'a'+1)%MOD,a[1]=(a[1]*base+t[1][j]-'a'+1)%MOD;
			for(int j=r;j<len;++j){
				a[0]=(a[0]*base+t[0][j]-'a'+1)%MOD,a[1]=(a[1]*base+t[1][j]-'a'+1)%MOD;
//				printf("[%d,%d]",i,j);
//				cout<<tmp[0]<<' '<<tmp[1]<<'\n';
				if(mp.find(mkp(a[0],a[1]))!=mp.end()) cnt+=mp[mkp(a[0],a[1])];
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
