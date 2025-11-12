#include<bits/stdc++.h>
using namespace std;
int in(){
	int ans=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) ans=ans*10+c-'0';
	return ans*f;
}
int n;
struct F{
	int d1,d2,d3;
	int d[4];
}a[100010];
bool cmp(F a,F b){
	if(a.d[1]-a.d[2]==b.d[1]-b.d[2]){
		if(a.d[2]-a.d[3]==b.d[2]-b.d[3]) return a.d[3]>b.d[3];
		return a.d[2]-a.d[3]>b.d[2]-b.d[3];
	}
	return a.d[1]-a.d[2]>b.d[1]-b.d[2];
}
int c[4];
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=in();
	while(T--){
		n=in();
		for(int i=1;i<=n;i++){
			a[i].d[1]=a[i].d1=in();
			a[i].d[2]=a[i].d2=in();
			a[i].d[3]=a[i].d3=in();
			sort(a[i].d+1,a[i].d+3+1,greater<int>());
		}
		sort(a+1,a+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].d[1]<<' '<<a[i].d[2]<<'\n';
//		}
		c[1]=0;c[2]=0;c[3]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int ma=-1,mi=0;
			if(c[1]+1<=n/2){
				if(ma<a[i].d1){
					ma=a[i].d1;
					mi=1;
				}
			}
			if(c[2]+1<=n/2){
				if(ma<a[i].d2){
					ma=a[i].d2;
					mi=2;
				}
			}
			if(c[3]+1<=n/2){
				if(ma<a[i].d3){
					ma=a[i].d3;
					mi=3;
				}
			}
			ans+=ma;
			c[mi]++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0




*/
