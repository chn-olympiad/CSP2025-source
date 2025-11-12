#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,q;
int g2[N],sz[N];
const int mod=1e9+7;
char c[N],a[N],b[N];
long long p[N];
long long m1[N],m2[N],f1[N],f2[N];
int main(){
//	system("fc replace.out replace4.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<N;i++)p[i]=p[i-1]*131%mod;
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		for(int j=1;c[j];j++){
			m1[i]=m1[i]*131+(c[j]-'a');
			m1[i]%=mod;
			sz[i]++;
		}	
		scanf("%s",c+1);
		for(int j=1;c[j];j++){
			m2[i]=m2[i]*131+(c[j]-'a');
			m2[i]%=mod;
		}	
	}
	while(q--){
		int ans=0;
		scanf("%s",a+1);
		scanf("%s",b+1);
		int r=0,len=0,l=0;
		while(a[len+1])len++;
		l=len;
		for(int i=1;a[i];i++){
			if(a[i]!=b[i]){
				l=min(l,i);
				r=max(r,i);
			}
			f1[i]=f1[i-1]*131+(a[i]-'a');
			f2[i]=f2[i-1]*131+(b[i]-'a');
			f1[i]%=mod;
			f2[i]%=mod;
		}
		for(int i=1;i<=l;i++){
			for(int j=1;j<=n;j++){
				int k=i+sz[j]-1;
//				if(k>len)continue;
				if(k<r||k>len)continue;
				if((f1[k]-(f1[i-1]*p[k-i+1])%mod+mod)%mod==m1[j]&&(f2[k]-(f2[i-1]*p[k-i+1])%mod+mod)%mod==m2[j])ans++;
			}
		}
		printf("%d\n",ans);
	}	
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
