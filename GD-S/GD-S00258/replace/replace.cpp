#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N=2e3+10;
int n,q,i,j,h,slen[N],sdifl[N],sdifr[N],tlen,ans,tdifl,tdifr,ok;
char s[N][2][N],t[2][N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i){
		scanf("%s%s",s[i][0]+1,s[i][1]+1);
		slen[i]=strlen(s[i][0]+1);
		for(j=1;j<=slen[i];++j){
			if(s[i][0][j]!=s[i][1][j]){
				sdifl[i]=j;
				break;
			}
		}
		if(j==slen[i]+1){
			sdifl[i]=1000000;
			continue;
		}
		for(j=slen[i];j>=1;--j){
			if(s[i][0][j]!=s[i][1][j]){
				sdifr[i]=j;
				break;
			}
		}
	}
	while(q--){
		scanf("%s%s",t[0]+1,t[1]+1);
		if(strlen(t[0]+1)!=strlen(t[1]+1)){
			printf("0\n");
			continue;
		}
		tlen=strlen(t[0]+1);
		for(j=1;j<=tlen;++j){
			if(t[0][j]!=t[1][j]){
				tdifl=j;
				break;
			}
		}
		for(j=tlen;j>=1;--j){
			if(t[0][j]!=t[1][j]){
				tdifr=j;
				break;
			}
		}
		for(i=1,ans=0;i<=n;++i){
			ok=1;
			if(sdifr[i]-sdifl[i]!=tdifr-tdifl) continue;
			if(sdifl[i]>tdifl||tlen-tdifr<slen[i]-sdifr[i]) continue;
			for(j=1;j<=slen[i];++j){
				h=tdifl-(sdifl[i]-1)+(j-1);
				if(s[i][0][j]!=t[0][h]||s[i][1][j]!=t[1][h]){
					ok=0;
					break;
				}
			}
			ans+=ok;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//17:08-17:48-18:16-18:22
