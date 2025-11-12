#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k,t,p,ans,a[N],f[N][N];
struct sct{int l,r;}s[N*N];
bool cmp(sct A,sct B){return A.r<B.r;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[i][i]=a[i];
		if(a[i]==k)s[++t].l=i,s[t].r=i;
	}
	for(int i=2;i<=n;i++){
		for(int l=1,r=i;r<=n;l++,r++){
			f[l][r]=f[l][r-1]^a[r];
			if(f[l][r]==k)s[++t].l=l,s[t].r=r;
		}
	}
	sort(s+1,s+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(s[i].l>p){
			ans++;
			p=s[i].r;
		}
	}
	printf("%d",ans);
	return 0;
}