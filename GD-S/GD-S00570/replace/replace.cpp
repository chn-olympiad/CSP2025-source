#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,sst[200005],l[2],st,nd,ans,tsbp[2][200005],tsbt[2];
char s[2][5000005],t[2][5000005];
bool tsb=true;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	sst[1]=1;
	for(int i=1;i<=n;i++){
		scanf("%s %s",s[0]+sst[i],s[1]+sst[i]);
		sst[i+1]=sst[i]+strlen(s[0]+sst[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=sst[i];j<sst[i+1];j++){
			if(s[0][j]=='a' || s[0][j]=='b'){
				if(s[0][j]=='b'){
					if(tsbp[0][i]==0)tsbp[0][i]=j;
				    else tsb=false;
				}
			}
			else tsb=false;
			if(s[1][j]=='a' || s[1][j]=='b'){
				if(s[1][j]=='b'){
					if(tsbp[1][i]==0)tsbp[1][i]=j;
				    else tsb=false;
				}
			}
			else tsb=false;
		}
		if(!tsb)break;
	}
	while(q--){
		ans=0;
		scanf("%s %s",t[0]+1,t[1]+1);
		l[0]=strlen(t[0]+1);
		l[1]=strlen(t[1]+1);
		if(l[0]!=l[1]){
			printf("0\n");
			continue;
		}
		st=l[0],nd=1,tsbt[0]=tsbt[1]=0;
		for(int i=1;i<=l[0];i++){
			if(t[0][i]=='a' || t[0][i]=='b'){
				if(t[0][i]=='b'){
					if(tsbt[0]==0)tsbt[0]=i;
				    else tsb=false;
				}
			}
			else tsb=false;
			if(t[1][i]=='a' || t[1][i]=='b'){
				if(t[1][i]=='b'){
					if(tsbt[1]==0)tsbt[1]=i;
				    else tsb=false;
				}
			}
			else tsb=false;
			if(t[0][i]!=t[1][i])st=min(st,i),nd=max(nd,i);
		}
		if(tsb){
			for(int i=1;i<=n;i++)
			    if(tsbp[1][i]-tsbp[0][i]==tsbt[1]-tsbt[0] && tsbt[0]-tsbp[0][i]+sst[i]>=1 && tsbt[0]-tsbp[0][i]+sst[i+1]<=l[0]+1)
			        ans++;
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			bool x;
			for(int j=max(0,nd-(sst[i+1]-sst[i]));j<=min(st-1,l[0]-(sst[i+1]-sst[i]));j++){
				x=true;
				for(int k=1;k<=sst[i+1]-sst[i];k++)
				    if(t[0][j+k]!=s[0][sst[i]+k-1]){
				    	x=false;
				    	break;
				}
				if(x)for(int k=1;k<=sst[i+1]-sst[i];k++)
				    if(t[1][j+k]!=s[1][sst[i]+k-1]){
				    	x=false;
				    	break;
				}
				if(x)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
