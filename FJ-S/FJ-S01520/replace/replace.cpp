#include<bits/stdc++.h>
using namespace std;
int n,thres,ans;
char s1[1020][1020],s2[1020][1020],t1[1020],t2[1020],temp[1020];
int len1,len2,lenp1[1020],lenp2[1020];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&thres);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1[i],s2[i]);
		lenp1[i]=strlen(s1[i]);
		lenp2[i]=strlen(s2[i]);
	}
	while(thres--){
		ans=0;
		scanf("%s%s",t1,t2);
		len1=strlen(t1);
		len2=strlen(t2);
		for(int i=0;i<len1;i++){
			for(int k=1;k<=n;k++){
				bool flag=true;
				for(int j=i;j<i+lenp1[k];j++)
					if(t1[j]!=s1[k][i-j]){
						flag=false;
						break;
					}
				if(flag){
					for(int j=0;j<len1;j++)
						temp[j]=t1[j];
					for(int j=i;j<i+lenp2[k];j++)
						temp[j]=s2[k][i-j];
					bool flag2=true;
					for(int j=0;j<len2;j++)
						if(temp[j]!=t2[j]){
							flag2=false;
							break;
						}
					ans+=flag2;
				}
			}
		}
		printf("%d\n",ans);
//		puts("0");
	}
	return 0;
}
