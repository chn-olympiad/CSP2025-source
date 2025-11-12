#include <bits/stdc++.h>
using namespace std;
int T,n,s[3][60000],cnt[3];
long long ans;
int f1(int a,int b,int c){
	int o;
	o=max(a,max(b,c));
	if(o==a) return 0;
	if(o==b) return 1;
	if(o==c) return 2; 
}
void enter(int a,int b,int c,int p){
	cnt[p]++;
	s[p][cnt[p]]=c-b;
	ans+=c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	int a[3];
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[0],&a[1],&a[2]);
		    int p=f1(a[0],a[1],a[2]);
		    sort(a,a+3);
		    enter(a[0],a[1],a[2],p);
		}
		for(int i=0;i<3;i++){
			if(cnt[i]>(n/2)){
				sort(s[i]+1,s[i]+1+cnt[i]);
				int k=cnt[i]-(n/2);
				for(int j=1;j<=k;j++){
					ans-=s[i][j]; 
				}
			}
		}
		printf("%ld\n",ans);
		memset(s,0,sizeof(s));
		memset(cnt,0,sizeof(cnt));
		ans=0;
	}
	return 0;
} 
