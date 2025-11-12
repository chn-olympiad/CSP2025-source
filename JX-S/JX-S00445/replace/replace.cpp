#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
const ll mod=998244353;
const ll bs=131;
int n,q;
string s[maxn][2],t[maxn][2];
int sL[maxn],sR[maxn],tL[maxn],tR[maxn];
pair<ll,ll> hs[maxn],ht[maxn];
int a[maxn],b[maxn];
int ans[maxn];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int tn;cin>>tn>>q;
	for(int i=1;i<=tn;i++){
		++n;cin>>s[n][0]>>s[n][1];
		if(s[n][0]==s[n][1]) n--;
	}for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=n;i++){
		sL[i]=0;while(s[i][0][sL[i]]==s[i][1][sL[i]]) sL[i]++;
		sR[i]=s[i][0].size()-1;
		while(s[i][0][sR[i]]==s[i][1][sR[i]]) sR[i]--;
	}
	for(int i=1;i<=q;i++){
		tL[i]=0;while(t[i][0][tL[i]]==t[i][1][tL[i]]) tL[i]++;
		tR[i]=t[i][0].size()-1;
		while(t[i][0][tR[i]]==t[i][1][tR[i]]) tR[i]--;
	}
	for(int i=1;i<=n;i++){
		ll sm[2]={0,0};
		for(int x:{0,1})
		for(int j=sL[i];j<=sR[i];j++) sm[x]=(sm[x]*bs%mod+s[i][x][j])%mod;
		hs[i]={sm[0],sm[1]};
	}
	for(int i=1;i<=q;i++){
		ll sm[2]={0,0};
		for(int x:{0,1})
		for(int j=tL[i];j<=tR[i];j++) sm[x]=(sm[x]*bs%mod+t[i][x][j])%mod;
		ht[i]={sm[0],sm[1]};
	}
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<=q;i++) b[i]=i;
	sort(a+1,a+n+1,[](int x,int y){return hs[x]<hs[y];});
	sort(b+1,b+q+1,[](int x,int y){return ht[x]<ht[y];});
	for(int i=1,j;i<=n;i=j+1){
		j=i;while(j<=n&&hs[a[j]]==hs[a[i]]) j++;j--;
		//printf("%d %d\n",i,j);
		int k=1,o=1;
		for(k=1;k<=q;k++) if(ht[b[k]]>=hs[a[i]]) break;
		for(o=1;o<=q;o++) if(ht[b[o]]>hs[a[i]]) break;
		o--;if(o<k) continue;
		for(int w=i;w<=j;w++) for(int e=k;e<=o;e++){
			int flg=1;
			for(int u=sL[a[w]]-1,c=tL[b[e]]-1;u>=0;u--,c--)
				if(c<0||s[a[w]][0][u]!=t[b[e]][0][c]) flg=0;
			for(int u=sR[a[w]]+1,c=tR[b[e]]+1;u<s[a[w]][0].size();u++,c++)
				if(c>=t[b[e]][0].size()||s[a[w]][0][u]!=t[b[e]][0][c]) flg=0;
			ans[b[e]]+=flg;
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
