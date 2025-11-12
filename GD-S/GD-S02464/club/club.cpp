#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int T,n,s[N][4],mx[N],t[N],cnt,f[4],m,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);while(T--){
		scanf("%d",&n);m=n/2;
		f[1]=f[2]=f[3]=0;ans=cnt=0;
		for(int i=1;i<=n;i++){
			mx[i]=1;
			for(int j=1;j<4;j++){
				scanf("%d",&s[i][j]);
				if(s[i][j]>s[i][mx[i]]) mx[i]=j;
			}f[mx[i]]++;
			ans+=s[i][mx[i]];
		}for(int p=1;p<4;p++) if(f[p]>m){
			for(int i=1;i<=n;i++) if(mx[i]==p){
				t[++cnt]=0;
				for(int j=1;j<4;j++) if(j!=mx[i]) t[cnt]=max(t[cnt],s[i][j]);
				t[cnt]=s[i][mx[i]]-t[cnt];
			}sort(1+t,1+cnt+t);
			for(int i=f[p]-m;i;i--) ans-=t[i];
		}printf("%d\n",ans);
	}fclose(stdin);fclose(stdout); 
return 0;}
