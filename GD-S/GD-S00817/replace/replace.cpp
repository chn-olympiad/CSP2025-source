#include<bits/stdc++.h>
#define N 1000005
#define M 10005
using namespace std;
int n,m;
char a[M][N],b[M][N];
char c[M][N],d[M][N];
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) 
		scanf("%s%s",&a[i],&b[i]);
	for(int i=0;i<m;i++){
		ans=0;
		scanf("%s%s",&c[i],&d[i]);
		for(int j=0;j<strlen(c[i]);j++){
			for(int l=0;l<n;l++){
				bool p=1;
				for(int k=0;k<strlen(a[l]);k++)
					if(a[l][k]!=c[i][j+k]||b[l][k]!=d[i][j+k]){
						p=0;
						break;	
					}
				if(p){
					for(int k=strlen(a[l])+j;k<strlen(c[i]);k++)
						if(c[i][k]!=d[i][k]){
						p=0;
						break;	
					}
					if(p){
						ans++;	
						//printf("%d\n",l);
					}
				}	
			}
			if(c[i][j]!=d[i][j]) break;
		}
		printf("%d\n",ans);		
	}
	return 0;
}
