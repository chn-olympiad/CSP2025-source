#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int T,n;
int ans=0;
int a[100005][4];
int f[10];
int w[100005];
int k[100005];
inline void work(){
	scanf("%d",&n);
	ans=0; 
	for(int i=1;i<=n;i++){
		for(int l=1;l<=3;l++)scanf("%d",&a[i][l]);
	}
	f[1]=f[2]=f[3]=0;
	for(int i=1;i<=n;i++){
		int id,x=-1;
		id=1,x=a[i][1];
		if(a[i][2]>x){
			id=2;
			x=a[i][2];
		}
		if(a[i][3]>x){
			id=3;
			x=a[i][3];
		}
		ans=ans+x;
		f[id]++;
		k[i]=id;
	}
//	cout<<f[2]<<"***"<<endl;
	if(max(f[1],max(f[2],f[3]))<=n/2){
		printf("%d\n",ans);
		return;
	}
	int bj=1;
	if(f[1]<f[2])bj=2;
	if(f[bj]<f[3])bj=3;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(k[i]==bj){
			w[++cnt]=INF;
			for(int l=1;l<=3;l++){
				if(bj==l)continue;
				w[cnt]=min(a[i][bj]-a[i][l],w[cnt]);
			}
		}
	}
//	cout<<cnt<<"$%^&"<<endl;
	sort(w+1,w+cnt+1);
	int wasd=f[bj]-n/2;
/*	for(int i=1;i<=cnt;i++){
		cout<<w[i]<<"^^^";
	}
	cout<<endl;*/
	for(int i=1;i<=wasd;i++)ans-=w[i];
	printf("%d\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)work(); 
}
