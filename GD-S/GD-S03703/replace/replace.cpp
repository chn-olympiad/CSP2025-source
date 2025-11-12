#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,m,t,o;
char s1[N][N],s2[N][N];
int len1[N],len2[N];
char t1[N],t2[N];
char c[N]; int len;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&o);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1[i],s2[i]);
		len1[i]=strlen(s1[i]); len2[i]=strlen(s2[i]);
		for(int j=len1[i];j>=1;j--){
			s1[i][j]=s1[i][j-1]; 
		}
		s1[i][0]=0;
		for(int j=len2[i];j>=1;j--){
			s2[i][j]=s2[i][j-1]; 
		}
		s2[i][0]=0;
	}
	while(o--){
		scanf("%s%s",t1,t2); m=strlen(t1); t=strlen(t2);
		for(int i=m;i>=1;i--){
			t1[i]=t1[i-1]; 
		}
		t1[0]=0;
		for(int i=t;i>=1;i--){
			t2[i]=t2[i-1]; 
		}
		t2[0]=0;
		int ans=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(m-len1[j]+len2[j]!=t||i+len1[j]-1>m) continue ; 
				bool flag=true;
				for(int k=i;k<=i+len1[j]-1;k++){
					if(s1[j][k-i+1]==t1[k]) continue ;
					flag=false; break;
				}
				if(!flag) continue ;
				for(int k=1;k<i;k++) c[++len]=t1[k];
				for(int k=1;k<=len2[j];k++) c[++len]=s2[j][k];
				for(int k=i+len1[j];k<=m;k++) c[++len]=t1[k];
				flag=true;
				for(int k=1;k<=t;k++){
					if(c[k]!=t2[k]){
						flag=false; break;
					}
				}
				ans=ans+flag;
				for(int k=1;k<=len;k++){
					c[k]=0;
				}
				len=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
