#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,x,ans,ca,cb,cc;
struct node{
	int mmax,cmax,mp,cp,cz;
	bool operator<(const node &w){
		if(cz!=w.cz) return cz>w.cz;
		return mmax>w.mmax;
	}
}a[100010];
struct point{
	int d,pos;
	bool operator<(const point &w){
		return d>w.d;
	}
}b[100010][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ca=cb=cc=ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)
				cin>>x,b[i][j]={x,j};
			sort(b[i],b[i]+3);
			a[i]={b[i][0].d,b[i][1].d,b[i][0].pos,b[i][1].pos,b[i][0].d-b[i][1].d};
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(!a[i].mp&&ca+1<=n/2) ca++,ans+=a[i].mmax;
			else if(!a[i].mp&&ca+1>n/2){
				ans+=a[i].cmax;
				if(a[i].cp==1) cb++;
				if(a[i].cp==2) cc++;
			}
			if(a[i].mp==1&&cb+1<=n/2) cb++,ans+=a[i].mmax;
			else if(a[i].mp==1&&cb+1>n/2){
				ans+=a[i].cmax;
				if(a[i].cp==0) ca++;
				if(a[i].cp==2) cc++;
			}
			if(a[i].mp==2&&cc+1<=n/2) cc++,ans+=a[i].mmax;
			else if(a[i].mp==2&&cc+1>n/2){
				ans+=a[i].cmax;
				if(a[i].cp==1) cb++;
				if(a[i].cp==0) ca++;
			}
		}
		cout<<ans<<'\n';
	}
}
/*
0秒猜出为贪心
我是N2羚羊 我的锣鼓UID是 1105085
我要起飞！！！
我要使用N2加速！！！ 
我要上GD迷惑行为大赏！！ 
所有人RP+=INF!!! 
*/
