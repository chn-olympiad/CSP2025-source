#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int o,n,a[N][5],id[N],b[N],tg[5];
int c[N],len;
void mems()
{
	for(int i=1;i<=n;i++){
		a[i][1]=0; a[i][2]=0; a[i][3]=0;
		id[i]=0; b[i]=0;
	}
	tg[1]=0; tg[2]=0; tg[3]=0;
	for(int i=1;i<=len;i++) c[i]=0;
	len=0; n=0;
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&o);
	while(o--){
		scanf("%d",&n); int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				id[i]=1; b[i]=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				id[i]=2; b[i]=a[i][2]-max(a[i][1],a[i][3]);
			}
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				id[i]=3; b[i]=a[i][3]-max(a[i][1],a[i][2]);
			}
			tg[id[i]]++; ans=ans+a[i][id[i]];
		}
		int ct=0,vt=0;
		if(tg[1]>=tg[2]&&tg[1]>=tg[3]) ct=tg[1],vt=1;
		else if(tg[2]>=tg[1]&&tg[2]>=tg[3]) ct=tg[2],vt=2;
		else if(tg[3]>=tg[1]&&tg[3]>=tg[2]) ct=tg[3],vt=3;
		ct=max(0,ct-n/2);
		for(int i=1;i<=n;i++){
			if(id[i]==vt) c[++len]=b[i];
		}
		sort(c+1,c+len+1);
		for(int i=1;i<=ct;i++){
			ans=ans-c[i];
		}
		printf("%d\n",ans); mems();
	}
	return 0;
}
