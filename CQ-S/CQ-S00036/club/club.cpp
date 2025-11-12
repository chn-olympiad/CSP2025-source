#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define il inline
using namespace std;
namespace starlit{
	int n;
	const int maxn=1e5+5;
	struct node{
		int x,y,z;
		int md;
	}a[maxn];
	int x[maxn],y[maxn],z[maxn];
	int xl=0,yl=0,zl=0;
	bool cmpx(int l,int r){
		return a[l].x+a[r].md>a[r].x+a[l].md;
	}
	bool cmpy(int l,int r){
		return a[l].y+a[r].md>a[r].y+a[l].md;
	}
	bool cmpz(int l,int r){
		return a[l].z+a[r].md>a[r].z+a[l].md;
	}
	void slove(){
		cin>>n;
		xl=yl=zl=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				x[++xl]=i;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				y[++yl]=i;
			}
			else{
				z[++zl]=i;
			}
			int mx=max(a[i].x,max(a[i].y,a[i].z));
			int mn=min(a[i].x,min(a[i].y,a[i].z));
			if(mx!=a[i].x&&mn!=a[i].x){
				a[i].md=a[i].x;
			}
			else if(mx!=a[i].y&&mn!=a[i].y){
				a[i].md=a[i].y;
			}
			else{
				a[i].md=a[i].z;
			}
		}
		if(xl*2>n){
//			cout<<"x need balance:"<<xl<<"\n";
			sort(x+1,x+xl+1,cmpx);
			for(int i=n/2+1;i<=xl;i++){
				int j=x[i];
				if(a[j].y>a[j].z){
					y[++yl]=j;
				}
				else z[++zl]=j;
			}
			xl=n/2;
		}
		else if(yl*2>n){
//			cout<<"y need balance:"<<yl<<"\n";
			sort(y+1,y+yl+1,cmpy);
			for(int i=n/2+1;i<=yl;i++){
				int j=y[i];
				if(a[j].x>a[j].z){
					x[++xl]=j;
				}
				else z[++zl]=j;
			}
			yl=n/2;
		}
		else if(zl*2>n){
//			cout<<"z need balance:"<<zl<<"\n";
			sort(z+1,z+zl+1,cmpz);
			for(int i=n/2+1;i<=zl;i++){
				int j=z[i];
				if(a[j].y>a[j].x){
					y[++yl]=j;
				}
				else x[++xl]=j;
			}
			zl=n/2;
		}
		int cnt=0;
		for(int i=1;i<=xl;i++){
			cnt+=a[x[i]].x;
//			cout<<a[x[i]].x<<' ';
		}
		for(int i=1;i<=yl;i++){
			cnt+=a[y[i]].y;
//			cout<<a[y[i]].y<<' ';
		}
		for(int i=1;i<=zl;i++){
			cnt+=a[z[i]].z;
//			cout<<a[z[i]].z<<' ';
		}
//		cout<<'\n';
		cout<<cnt<<'\n';
	}
	signed main(){
		int _test_;
		cin>>_test_;
		while(_test_--){
			slove();
		}
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	starlit::main();
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

神秘大样例4点4
可能会被卡掉一些分数
100pts-?

edge surf 记录
计时赛：24.85s
障碍赛：104
无尽：34348
金币：5176
小恐龙：10223 
成绩最好的一次:(
关于我在冲浪里对着一堆人乱撞（开代码后） 

uid 998158（听说死前把身份证放嘴里可以证明身份，uid放代码里呢？） 

AFO了，但是没有感言
希望文化课可以取得一个好成绩
政治和历史是真的菜

100+100+0+0=200pts?

可能1=吗……
算了 
生死看淡 
烂命一条就是干（ 
 
*/
