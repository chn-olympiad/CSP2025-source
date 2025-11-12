#include <bits/stdc++.h>
#define N 100015
using namespace std;
int T,n,cnta,cntb,cntc,ans;
struct Node{
	int val;
	int tpe;
};
Node dell[N];
bool cmp1(int x,int y){
	return x>y;
}
bool cmpa(Node x,Node y){
	if(x.tpe!=y.tpe) return x.tpe<y.tpe;
	return x.val<y.val;
}
void init(){
	for(int i=1;i<=N-5;i++){
		dell[i].tpe=0;
		dell[i].val=0;
	}
	ans=0;
	cnta=0;
	cntb=0;
	cntc=0;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int temp[4];
			temp[0]=0;
			scanf("%d%d%d",&temp[1],&temp[2],&temp[3]);
			if(temp[1]>=temp[2]&&temp[1]>=temp[3]){
				cnta++;
				dell[i].tpe=1;
			}
			else if(temp[2]>=temp[1]&&temp[2]>=temp[3]){
				cntb++;
				dell[i].tpe=2;
			}
			else{
				cntc++;
				dell[i].tpe=3;
			}
			sort(temp+1,temp+4,cmp1);
			dell[i].val=temp[1]-temp[2];
			ans+=temp[1];
		}
		if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2){
			printf("%d\n",ans);
			continue;
		}

		int ex=0;
		sort(dell+1,dell+n+1,cmpa);
		if(cnta>n/2){
			ex=cnta-n/2;
			for(int i=1;i<=ex;i++) ans-=dell[i].val;
		}
		else if(cntb>n/2){
			ex=cntb-n/2;
			for(int i=1;i<=ex;i++) ans-=dell[i+cnta].val;
		}
		else{
			ex=cntc-n/2;
			for(int i=1;i<=ex;i++) ans-=dell[i+cnta+cntb].val;
		}
		printf("%d\n",ans);
	}
	return 0;
}

