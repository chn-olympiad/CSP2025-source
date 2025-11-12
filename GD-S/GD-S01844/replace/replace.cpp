#include<bits/stdc++.h>
using namespace std;
int n,m,q,ans,l[200005],r[200005];
char s[5000005],t[500005],s1[5000005],s2[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s),l[i]=r[i-1]+1,r[i]=r[i-1]+strlen(s);
		for(int j=0;j<=r[i]-l[i];j++) s1[j+l[i]]=s[j];
		scanf("%s",s);
		for(int j=0;j<=r[i]-l[i];j++) s2[j+l[i]]=s[j];
	}
	while(q--){
		scanf("%s%s",s,t),m=strlen(s),ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				if(j+r[i]-l[i]>=m) break;
				int f=0;
				for(int x=j,y=l[i];y<=r[i];x++,y++)
					if(s[x]!=s1[y]||t[x]!=s2[y]){
						f=1;
						break;
					}
				if(f) continue;
				for(int k=0;k<j;k++) if(s[k]!=t[k]){f=1;break;}
				for(int k=j+r[i]-l[i]+1;k<m;k++) if(s[k]!=t[k]){f=1;break;}
				if(!f){ans++;break;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
