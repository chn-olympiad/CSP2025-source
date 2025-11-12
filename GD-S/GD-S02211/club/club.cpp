#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
int T,n,a[maxn][3],w[maxn],c[3][maxn],cnt[3],ans;
int calcu(int x,int y){
	if(y==0){
		return a[x][0]-max(a[x][1],a[x][2]);
	}
	if(y==1){
		return a[x][1]-max(a[x][0],a[x][2]);
	}
	if(y==2){
		return a[x][2]-max(a[x][0],a[x][1]);
	}
	return 1e9;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt[0]=0;cnt[1]=0;cnt[2]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int d=0;
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				d=0;
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				d=1;
			}else{
				d=2;
			}
			c[d][++cnt[d]]=i;
			ans+=a[i][d];
		}
		for(int t=0;t<=2;t++){
			if(cnt[t]>n/2){
				//去除t社团社员
				for(int i=1;i<=cnt[t];i++){
					c[t][i]=calcu(c[t][i],t);
				}
				sort(c[t]+1,c[t]+1+cnt[t]);
				for(int i=1;i<=cnt[t]-(n/2);i++){
					ans-=c[t][i];
				}
			}
		}
		cout<<ans<<"\n";
	}
} 
//100pts
