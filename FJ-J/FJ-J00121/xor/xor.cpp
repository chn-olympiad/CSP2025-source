#include <bits/stdc++.h>
using namespace std;
int a[500010],sum[500010];
pair<int,int> s[500010];
int m,maxx;
void dfs(int k,int p,int l,int r){
	if (k==m){
		maxx=max(maxx,p);
		return ;
	}
	for (int i=k+1;i<=m;i++){
		if (s[i].first>r||s[i].second<l){
			dfs(i,p+1,min(l,s[i].first),max(r,s[i].second));
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int flg1=1,flg2=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]!=1){
			flg1=0;
		}
		if (a[i]>1){
			flg2=0;
		}
		sum[i]=sum[i-1]^a[i];
	}
	if (flg1){
		if (k){
			printf("%d",n);
		}
		else{
			printf("%d",n/2);
		}
	}
	else if (flg2){
		if (k){
			int cnt=a[1]+a[2]+((a[1]==a[2])&&!a[1]),cut=0;
			for (int i=3;i<=n;i++){
				cnt+=a[i];
				if (!a[i]){
					cut++;
				}
				else{
					cnt+=cut/2;
					cut=0;
				}
			}
			cnt+=cut/2;
			printf("%d",cnt);
		}
		else{
			int cnt=!a[1]+!a[2]+((a[1]==a[2])&&a[1]),cut=0;
			for (int i=3;i<=n;i++){
				cnt+=!a[i];
				if (a[i]){
					cut++;
				}
				else{
					cnt+=cut/2;
					cut=0;
				}
			}
			cnt+=cut/2;
			printf("%d",cnt);
		}
	}
	else{
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if ((sum[j]^sum[i-1])==k){
					m++;
					s[m]={i,j};
					break;
				}
			}
		}
		dfs(0,0,n+1,0);
		printf("%d",maxx);
	}
	return 0;
}
