#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,S,m,c[20],f[262144][20];
char t[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%d%d",&n,&m);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	S=(1<<n)-1;
	f[0][0]=1;
	for(int s=0;s<S;s++){
		int p=__builtin_popcount(s)+1;
		for(int j=0;j<p;j++){
			for(int k=1;k<=n;k++){
				if(!(s&(1<<(k-1)))){
					if(t[p]=='0'){
						f[s^(1<<(k-1))][j+1]+=f[s][j];
					}
					else{
						if(j>=c[k])f[s^(1<<(k-1))][j+1]+=f[s][j];
						else f[s^(1<<(k-1))][j]+=f[s][j];
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)ans+=f[S][i];
	printf("%d",ans);
}
