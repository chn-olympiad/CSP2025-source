#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>void read(T&x){
	x=0;char c;int sign=1;
	do{c=getchar();if(c=='-')sign=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	x=x*sign;
}
const int N=2e5+666;
int T,n,a[N][7],t[4],dp[N];
bool flag1=0,flag2=0;
struct club{
	int maxs,idx,id;
	int maxs2,idx2;
}p[N];
bool cmp(club x,club y){
	if(x.maxs!=y.maxs)return x.maxs>y.maxs;
	else return x.maxs2>y.maxs2;
}
void solve(){
	read(n);
	int maxn=n/2;//<=
	int ans=0;
	if(n==2){
		int a1,b1,c1;
		int a2,b2,c2;
		cin>>a1>>b1>>c1;
		cin>>a2>>b2>>c2;
		ans=max(a1+b2,a1+c2);
		ans=max(ans,max(b1+a2,b1+c2));
		ans=max(ans,max(c1+a2,c1+b2));
		cout<<ans;
		return;
	}
	for(int i=1;i<=n;i++){
		int maxfeel=-1,maxclub=-1;
		int mafeel=-1,maclub=-1;
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int j=1;j<=3;j++){
			if(a[i][j]>=maxfeel){
				mafeel=maxfeel;
				maxfeel=a[i][j];
				maclub=maxclub;
				maxclub=j;
			}
			else if(a[i][j]>mafeel){
				mafeel=a[i][j];
				maclub=j;
			}
		}
		//cout<<maxclub<<" "<<maclub<<"\n";
		p[i].maxs=maxfeel;
		p[i].idx=maxclub;
		p[i].maxs2=mafeel;
		p[i].idx2=maclub;
		p[i].id=i;
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++){
		//cout<<p[i].id<<" "<<p[i].idx<<":"<<p[i].maxs<<" "<<p[i].idx2<<":"<<p[i].maxs2<<"#\n";
		if(t[p[i].idx]<maxn){
			t[p[i].idx]++;
			ans+=p[i].maxs;
		}
		else{
			t[p[i].idx2]++;
			ans+=p[i].maxs2;
		}
	}
	cout<<ans<<"\n";
	t[1]=t[2]=t[3]=t[0]=0;
	return;
}
//void solve(){
//	read(n);
//	int maxn=n/2;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			read(a[i][j]);
//		}
//		if(a[i][2]!=0||a[i][3]!=0)flag1=1;
//		if(a[i][3]!=0)flag2=1;
//	}
////	if(!flag){
////		
////	}
//	for(int i=1;i<=n;i++){
//		for(int j=n;j>=1;j--){
//			dp[j]=max(dp[j],max(max(dp[j-1]+a[i][1],dp[j-1]+a[i][2]),dp[j-1]+a[i][3]));
//		}
//	}
//	cout<<dp[n]<<"\n";
//	for(int i=0;i<=n;i++)dp[i]=0;
//	return;
//}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
