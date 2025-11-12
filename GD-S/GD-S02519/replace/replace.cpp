#include<bits/stdc++.h>
#define int long long
#define MAXN 5000005
#define N 200005
using namespace std;
const int mod=998244353,base=19491001;
int n,q,has[MAXN],chas[N][2],l[N],r[N],d[MAXN],ans,p[MAXN],ta[MAXN],tb[MAXN];
char ca[MAXN],cb[MAXN];
int tas[2][MAXN];
map<int,int>mp;
int cnt;
vector<int>v[MAXN];
int que(int l,int r,int *t){
	if(l<1||l>r)return 0;
	return (t[r]+mod-t[l-1]*p[r-l+1]%mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;for(int i=1;i<=MAXN-5;i++)p[i]=p[i-1]*base%mod;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",ca+1);
		scanf("%s",cb+1);
		int la=strlen(ca+1),lb=strlen(cb+1);
		ta[i]=la,tb[i]=lb;
		for(int j=1;j<=min(la,lb);j++){
			if(ca[j]!=cb[j]){
				l[i]=j;
				break;
			}
		}
		if(!l[i]){
			l[i]=min(la,lb)+1;
		}
		for(int j=1;j<=min(la,lb);j++){
			if(ca[la-j+1]!=cb[lb-j+1]){
				r[i]=la-j+1;
				break;
			}
		}
		if(!r[i]){
			r[i]=la-min(la,lb);
		}
		d[i]=lb-la;
		if(!mp[d[i]]){
			mp[d[i]]=++cnt;
			//cout<<d[i]<<' '<<cnt<<"\n";
		}
		v[cnt].push_back(i);
		for(int j=1;j<=la;j++)has[j]=(has[j-1]*base+ca[j])%mod;
		chas[i][0]=has[la];
		for(int j=1;j<=lb;j++)has[j]=(has[j-1]*base+cb[j])%mod;
		chas[i][1]=has[lb];
	}
	for(int i=1;i<=q;i++){
		scanf("%s",ca+1);
		scanf("%s",cb+1);
		int la=strlen(ca+1),lb=strlen(cb+1);
		if(!mp[lb-la]){
			printf("0\n");
			continue;
		}
		int pos=min(la,lb)+1;
		for(int j=1;j<=min(la,lb);j++){
			if(ca[j]!=cb[j]){
				pos=j;
				break;
			}
		}
		for(int j=1;j<=la;j++)tas[0][j]=(tas[0][j-1]*base+ca[j])%mod;
		for(int j=1;j<=lb;j++)tas[1][j]=(tas[1][j-1]*base+cb[j])%mod;
		int ans=0;
		for(int j=0;j<(int)v[mp[lb-la]].size();j++){
			int x=v[mp[lb-la]][j];
			//cout<<x<<' '<<pos-l[x]+1<<' '<<pos-l[x]+ta[x]<<' '<<pos-l[x]+tb[x]<<"\n";
			//cout<<que(pos-l[x]+1,pos-l[x]+ta[x],tas[0])<<' '<<chas[x][0]<<"\n";
			if(que(pos-l[x]+1,pos-l[x]+ta[x],tas[0])==chas[x][0]&&que(pos-l[x]+1,pos-l[x]+tb[x],tas[1])==chas[x][1]&&que(pos-l[x]+ta[x]+1,la,tas[0])==que(pos-l[x]+tb[x]+1,lb,tas[1])){
				if(pos-l[x]+ta[x]<=la)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

