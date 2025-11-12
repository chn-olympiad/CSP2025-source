#include<bits/stdc++.h>

using namespace std;
using ll=long long;

const int kMaxN=1e4+100,M=1e6+100;

int n,m,k,f[kMaxN],s[kMaxN],c,a[15][kMaxN],C[15],O[300][kMaxN],O1[300][kMaxN],CNT[300],CNT1[300],D[1<<15],BH[kMaxN<<1],TT,ZZ[15],rx,ry;
ll ans,sum[1<<15],dp[1<<15];
array<int,3>e[M],E[M<<1];
vector<int>T[15];

int R(int x){return f[x]?f[x]=R(f[x]):x;}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k,D[0]=1;
	for(int i=1;i<=m;i++){
		cin>>e[i][1]>>e[i][2]>>e[i][0];
	}
	sort(e+1,e+m+1),fill(s,s+n+1,1);
	for(int i=1;i<=m;i++){
		if((rx=R(e[i][1]))!=(ry=R(e[i][2]))){
			s[rx]<s[ry]&&(swap(rx,ry),0),s[rx]+=s[ry],f[ry]=rx,E[++c]=e[i],ans+=e[i][0],O[1][++CNT[1]]=c;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>C[i],ZZ[i]=c;
		for(int j=1;j<=n;j++){
			cin>>a[i][j],E[++c]={a[i][j],j,i+n};
		}
		sort(E+c-n+1,E+c+1);
	}
	for(int i=1,l;i<(1<<k);i++){
		l=0;
		for(int j=0;j<k;j++){
			l+=(i>>j)&1;
		}
		T[l].push_back(i);
	}
	for(int i=1,ii=0;i<=k;i++){
		ii=0;
		for(int j:T[i]){
			ii++,sum[j]=sum[j^(j&(-j))];
			for(int l=0;l<k;l++){
				if((j>>l)&1){
					TT=ZZ[l+1],sum[j]+=C[l+1];
					break;
				}
			}
			for(int k=1,o=1,p=1;k<=CNT[D[j^(j&(-j))]]+n;k++){
				if(o>CNT[D[j^(j&(-j))]]||(p<=n&&E[TT+p][0]<E[O[D[j^(j&(-j))]][o]][0])){
					BH[k]=TT+p,p++;
				}else{
					BH[k]=O[D[j^(j&(-j))]][o],o++;
				}
			}
			fill(f,f+n+k+1,0),fill(s,s+n+k+1,1);
			for(int k=1;k<=CNT[D[j^(j&(-j))]]+n;k++){
				if((rx=R(E[BH[k]][1]))!=(ry=R(E[BH[k]][2]))){
					s[rx]<s[ry]&&(swap(rx,ry),0),s[rx]+=s[ry],f[ry]=rx,O1[ii][++CNT1[ii]]=BH[k],dp[j]+=E[BH[k]][0];
				}
			}
			D[j]=ii,ans=min(ans,dp[j]+sum[j]);
		}
		for(int j=1;j<=ii;j++){
			CNT[j]=CNT1[j];
			for(int k=1;k<=CNT[j];k++){
				O[j][k]=O1[j][k];
			}
		}
	}
	cout<<ans;
	return 0;
}
