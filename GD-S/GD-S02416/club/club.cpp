#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
#define int long long
int a[N][5],n;
int a1[N],b1[N],c1[N];
int suma,sumb,sumc;
//int dp[N][N]
int d[N];
bool cmpa(int x,int y){
	int aa=min(a[x][1]-a[x][2],a[x][1]-a[x][3]);
	int bb=min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
	return aa>bb;
}
bool cmpb(int x,int y){
	int aa=min(a[x][2]-a[x][1],a[x][2]-a[x][3]);
	int bb=min(a[y][2]-a[y][1],a[y][2]-a[y][3]);
	return aa>bb;
}
bool cmpc(int x,int y){
	int aa=min(a[x][3]-a[x][2],a[x][3]-a[x][1]);
	int bb=min(a[y][3]-a[y][2],a[y][3]-a[y][1]);
	return aa>bb;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	int ans=0;
	while(T--){
		suma=0,sumb=0,sumc=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=max(a[i][2],a[i][3])){
				suma++;
				a1[suma]=i;
				ans+=a[i][1];
			}else if(a[i][2]>=max(a[i][3],a[i][1])){
				sumb++;
				b1[sumb]=i;
				ans+=a[i][2];
			}else{
				sumc++;
				c1[sumc]=i;
				ans+=a[i][3];
			}
		}
		if(suma>n/2){
			sort(a1+1,a1+1+suma,cmpa);
			while(suma>n/2){
				if(a[a1[suma]][2]>a[a1[suma]][3]){
					ans-=a[a1[suma]][1]-a[a1[suma]][2];
				} else{
					ans-=a[a1[suma]][1]-a[a1[suma]][3];
				}
				suma--;
			}
		}
		if(sumb>n/2){
			sort(b1+1,b1+1+sumb,cmpb);
			while(sumb>n/2){
				if(a[b1[sumb]][1]>a[b1[sumb]][3]){
					ans-=a[b1[sumb]][2]-a[b1[sumb]][1];
				} else{
					ans-=a[b1[sumb]][2]-a[b1[sumb]][3];
				}
				sumb--;
			}
		}
		if(sumc>n/2){
			sort(c1+1,c1+1+sumc,cmpc);
			while(sumc>n/2){
				if(a[c1[sumc]][1]>a[c1[sumc]][2]){
					ans-=a[c1[sumc]][3]-a[c1[sumc]][1];
				} else{
					ans-=a[c1[sumc]][3]-a[c1[sumc]][2];
				}
				sumc--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
