#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,k,ans,o,a[100100][5],cnt[5],b[100100],c[100100],d[100100];
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();m=n/2;ans=0;k=0;
		for(int i=1;i<=n;i++){
			a[i][0]=read();a[i][1]=read();a[i][2]=read();
			b[i]=max(max(a[i][0],a[i][1]),a[i][2]);ans+=b[i];
		}
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]==b[i]){
				cnt[0]++;c[i]=0;
			}
			else if(a[i][1]==b[i]){
				cnt[1]++;c[i]=1;
			}
			else{
				cnt[2]++;c[i]=2;
			}
		}
		if(cnt[0]<=m&&cnt[1]<=m&&cnt[2]<=m){
			printf("%lld\n",ans);continue;
		}
		if(cnt[0]>m){
			o=cnt[0]-m;
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					d[++k]=a[i][0]-max(a[i][1],a[i][2]);
				}
			}
		}
		else if(cnt[1]>m){
			o=cnt[1]-m;
			for(int i=1;i<=n;i++){
				if(c[i]==1){
					d[++k]=a[i][1]-max(a[i][0],a[i][2]);
				}
			}
		}
		else{
			o=cnt[2]-m;
			for(int i=1;i<=n;i++){
				if(c[i]==2){
					d[++k]=a[i][2]-max(a[i][0],a[i][1]);
				}
			}
		}
		sort(d+1,d+1+k);
		for(int i=1;i<=o;i++)ans-=d[i];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
