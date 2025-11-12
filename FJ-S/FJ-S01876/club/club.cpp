#include<bits/stdc++.h>
using namespace std;
int n;
struct sa{
	int d[4];
	int ma1,ma2;
	int cha;
}ch[100010];
int a[100010],b[100010],c[100010];
int na,nb,nc;

void paia(){
	for(int i=1;i<na;i++){
		for(int j=j+1;j<=na;j++){
			if(ch[a[i]].cha>ch[a[j]].cha)
				swap(a[i],a[j]);
		}
	}
}
void paib(){
	for(int i=1;i<nb;i++){
		for(int j=j+1;j<=nb;j++){
			if(ch[b[i]].cha>ch[b[j]].cha)
				swap(b[i],b[j]);
		}
	}
}
void paic(){
	for(int i=1;i<nc;i++){
		for(int j=j+1;j<=nc;j++){
			if(ch[c[i]].cha>ch[c[j]].cha)
				swap(c[i],c[j]);
		}
	}
}

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		na=0,nb=0,nc=0;
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&ch[i].d[1]);
			scanf("%d",&ch[i].d[2]);
			scanf("%d",&ch[i].d[3]);
			ch[i].d[0]=-1;
			ch[i].ma1=0;
			ch[i].ma2=0;
			for(int j=1;j<=3;j++){
				if(ch[i].d[j]>ch[i].d[ch[i].ma1]){
					ch[i].ma2=ch[i].ma1;
					ch[i].ma1=j;
				}
				else if(ch[i].d[j]>ch[i].d[ch[i].ma2])
					ch[i].ma2=j;
			}
			ch[i].cha=ch[i].d[ch[i].ma1]-ch[i].d[ch[i].ma2];
			ans+=ch[i].d[ch[i].ma1];
			if(ch[i].ma1==1)
				a[++na]=i;
			else if(ch[i].ma1==2)
				b[++nb]=i;
			else
				c[++nc]=i;
		}
	//	printf("%d\n",ans);
		if(na>n/2){
			paia();
			for(int i=1;na>n/2;--na,i++){
				ans-=ch[a[i]].cha;
			}
		}
		else if(nb>n/2){
			paib();
			for(int i=1;nb>n/2;--nb,i++){
				ans-=ch[b[i]].cha;
			}
		}
		else if(nc>n/2){
			paic();
	//		for(int i=1;i<=nc;i++)
		//		printf("%d ",ch[c[i]].cha);
			for(int i=1;nc>n/2;--nc,i++){
			//	printf("%d %d\n",c[i],ch[c[i]].cha) ;
				ans-=ch[c[i]].cha;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

