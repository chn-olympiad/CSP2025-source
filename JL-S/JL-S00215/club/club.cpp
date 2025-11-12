#include<bits/stdc++.h>
using namespace std;
struct sss{
	long long a;
	long long b;
	long long c;
	long long n;
};
struct ss{
	long long a;
	long long b;
};
long long n,m,s,q=0,ad=0,bd=0,cd=0,mm=0;
sss a[100044];
ss am[10010],bm[10000],cm[10002];
bool c1(sss a,sss b){
	return a.a>b.a;
}
bool c2(sss a,sss b){
	return a.b>b.b;
}
bool c3(sss a,sss b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		q=0,ad=0,bd=0,cd=0,mm=0;
		scanf("%lld",&m);
		for(int j=1;j<=m;j++){
			cin>>a[j].a>>a[j].b>>a[j].c;
			a[j].n=j;
		}
		s=m/2;
		sort(a+1,a+m+1,c1);
		for(int j=1;j<=m;j++){
			am[j].a=a[j].n;
			am[j].b=a[j].a;
		}
		sort(a+1,a+m+1,c2);
		for(int j=1;j<=m;j++){
			bm[j].a=a[j].n;
			bm[j].b=a[j].b;
		}
		sort(a+1,a+m+1,c3);
		for(int j=1;j<=m;j++){
			cm[j].a=a[j].n;
			cm[j].b=a[j].c;
		}
		int yyy=max(max(max(a[1].c+a[2].b,a[1].a+a[2].b),max(a[1].a+a[2].c,a[1].b+a[2].a)),max(a[1].c+a[2].a,a[1].b+a[2].c));
		if(m==2){
			cout<<yyy;
		}else{
			for(int j=1;j<=m;j++){
				long long w=max(max(am[1].b,bm[1].b),cm[1].b);
				if(w==am[1].b&&ad+1<=s){
					am[1].b=0;
					mm+=w;
					ad++;
					for(int k=1;k<=m;k++){
						if(bm[k].a==am[1].a){
							for(int y=k+1;y<=m;y++){
								bm[y-1].a=bm[y].a;
								bm[y-1].b=bm[y].b;
							}
						}
						if(cm[k].a==am[1].a){
							for(int y=k+1;y<=m;y++){
								cm[y-1].a=cm[y].a;
								cm[y-1].b=cm[y].b;
							}
						}
					}
					for(int k=2;k<=m;k++){
						am[k-1].a=am[k].a;
						am[k-1].b=am[k].b;
					}
				}
				if(w==bm[1].b&&bd+1<=s){
					bm[1].b=0;
					mm+=w;
					bd++;
					for(int k=1;k<=m;k++){
						if(am[k].a==bm[1].a){
							for(int y=k+1;y<=m;y++){
								am[y-1].a=am[y].a;
								am[y-1].b=am[y].b;
							}
						}
						if(cm[k].a==bm[1].a){
							for(int y=k+1;y<=m;y++){
								cm[y-1].a=cm[y].a;
								cm[y-1].b=cm[y].b;
							}
						}
					}
					for(int k=2;k<=m;k++){
						bm[k-1].a=bm[k].a;
						bm[k-1].b=bm[k].b;
					}
				}
				if(w==cm[1].b&&cd+1<=s){
					cm[1].b=0;
					mm+=w;
					cd++;
					for(int k=1;k<=m;k++){
						if(bm[k].a==cm[1].a){
							for(int y=k+1;y<=m;y++){
								bm[y-1].a=bm[y].a;
								bm[y-1].b=bm[y].b;
							}
						}
						if(am[k].a==cm[1].a){
							for(int y=k+1;y<=m;y++){
								am[y-1].a=am[y].a;
								am[y-1].b=am[y].b;
							}
						}
					}
					for(int k=2;k<=m;k++){
						cm[k-1].a=cm[k].a;
						cm[k-1].b=cm[k].b;
					}
				}
			}
			printf("%lld\n",mm);
		}
	}
	return 0;
}
