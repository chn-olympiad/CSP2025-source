#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,t;
struct peop{
	int ma;
	int mb;
	int mc;
	int minu;
};
peop a[100001];
int maxxx(int x,int y){
	if(x>y)return x;
	else return y;
}
int minnn(int x,int y){
	if(x>y)return y;
	else return x;
}
void op(int x){
	int maxx=-1,minx=20001;
	maxx=maxxx(a[x].ma,maxxx(a[x].mb,a[x].mc));
	minx=minnn(a[x].ma,minnn(a[x].mb,a[x].mc));
	a[x].minu=maxx-(a[x].ma+a[x].mb+a[x].mc-maxx-minx);
	return;
}
bool cmp(peop x,peop y){
	return x.minu>y.minu;
}
int f_m(int x){
	int pos=1,maxx=0;
	if(a[x].ma>maxx){
		maxx=a[x].ma;
		pos=1;
	}
	if(a[x].mb>maxx){
		maxx=a[x].mb;
		pos=2;
	}
	if(a[x].mc>maxx){
		maxx=a[x].mc;
		pos=3;
	}
	return pos;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int cnta=0,cntb=0,cntc=0;
		int sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].ma,&a[i].mb,&a[i].mc);
			op(i);
		}
		sort(a+1,a+n+1,cmp);
		int po;
		for(int i=1;i<=n;i++){
			po=f_m(i);
			if(po==1){
				if(cnta*2<n){
					cnta++;
					sum+=a[i].ma;
				}else{
					if(a[i].mb>a[i].mc){
						cntb++;
						sum+=a[i].mb;
					}else{
						cntc++;
						sum+=a[i].mc;
					}
				}
			}else if(po==2){
				if(cntb*2<n){
					cntb++;
					sum+=a[i].mb;
				}else{
					if(a[i].ma>a[i].mc){
						cnta++;
						sum+=a[i].ma;
					}else{
						cntc++;
						sum+=a[i].mc;
					}
				}
			}else{
				if(cntc*2<n){
					cntc++;
					sum+=a[i].mc;
				}else{
					if(a[i].ma>a[i].mb){
						cnta++;
						sum+=a[i].ma;
					}else{
						cntb++;
						sum+=a[i].mb; 
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
