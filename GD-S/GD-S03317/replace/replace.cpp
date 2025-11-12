#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2010;
int n,q,m,cnt,L,R,ans,l[N];
char s1[1010][N],s2[1010][N];
char c1[N],c2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1[i]+1,s2[i]+1);
		l[i]=strlen(s1[i]+1);
	}
	while(q--){
		scanf("%s%s",c1+1,c2+1);
		m=strlen(c1+1),L=1e9,R=0,ans=0;
		for(int i=1;i<=m;i++){
			if(c1[i]!=c2[i])L=min(L,i),R=max(R,i);
		}
		for(int i=R;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(l[j]<(i-L+1)||l[j]>i)continue;
				ans++;
				for(int k=1,t=i-l[j]+1;k<=l[j];k++,t++){
					if(c1[t]!=s1[j][k]||c2[t]!=s2[j][k]){
						ans--;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
