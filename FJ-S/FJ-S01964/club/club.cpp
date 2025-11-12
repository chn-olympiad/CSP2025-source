#include<bits/stdc++.h>
using namespace std;
int a[100010][4];
int b[100010];
int cnt[4],s[100010];
void solve(){
	int n,ans=0;
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)s[i]=b[i]=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		int id=0;
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
			if(!id || a[i][j]>a[i][id])id=j;
		}
		cnt[id]++;
		ans+=a[i][id];
		s[i]=id;
	}
	int del=-1;
	if(cnt[1]>n/2)del=1;
	if(cnt[2]>n/2)del=2;
	if(cnt[3]>n/2)del=3;
	if(del==-1){
		printf("%d\n",ans);
		return ;
	}
	int m=0;
	for(int i=1;i<=n;i++){
		if(s[i]==del){
			int mn=1e9;
			for(int j=1;j<=3;j++){
				if(j==del)continue;
				mn=min(mn,a[i][del]-a[i][j]);
			}
			b[++m]=mn;
		}
	}
	sort(b+1,b+1+m);
	for(int i=1;i<=m-n/2;i++)ans-=b[i];
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve(); 
	return 0;
}
//100,14:45
