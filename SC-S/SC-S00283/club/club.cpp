#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
struct node{
	int v,idx,to_,idxx;
} b[N];
map<int,int> mp;
int cnt1=0,cnt2=0,cnt3=0;
int a[N][4],_1[N],_2[N],_3[N];
int n;
bool cmp(node x,node y){
	return x.v>y.v;
}
void change_1(){
	int x=0;
	for(int i=1;i<=cnt1;i++){
		int maxn=-0x3f3f3f3f,idx=0;
		if(_1[i]==-1) continue;
		for(int j=2;j<=3;j++){
			if(maxn<-a[_1[i]][1]+a[_1[i]][j]){
				maxn=-a[_1[i]][1]+a[_1[i]][j];
				idx=j;
			}
		}
		b[i]={maxn,_1[i],idx,i};
	}
	sort(b+1,b+1+cnt1,cmp);
	int cnt=mp[1]-n/2;
	for(int i=1;i<=cnt;i++){
		mp[b[i].to_]++;
		mp[1]--;
		_1[b[i].idxx]=-1;
		b[i].v=-0x3f3f3f3f;
		if(b[i].to_==2) _2[++cnt2]=b[i].idx;
		if(b[i].to_==3) _3[++cnt3]=b[i].idx;
	}
}
void change_2(){
	for(int i=1;i<=cnt2;i++){
		int maxn=-0x3f3f3f3f,idx=0;
		if(_2[i]==-1) continue;
		for(int j=1;j<=3;j++){
			if(j==2) continue;
			if(maxn<-a[_2[i]][2]+a[_2[i]][j]){
				maxn=-a[_2[i]][2]+a[_2[i]][j];
				idx=j;
			}
		}
		b[i]={maxn,_2[i],idx,i};
	}
	sort(b+1,b+1+cnt2,cmp);
	int cnt=mp[2]-n/2;
	for(int i=1;i<=cnt;i++){
		mp[b[i].to_]++;
		mp[2]--;
		_2[b[i].idxx]=-1;
		b[i].v=-0x3f3f3f3f;
		if(b[i].to_==1) _1[++cnt1]=b[i].idx;
		if(b[i].to_==3) _3[++cnt3]=b[i].idx;
	}
}
void change_3(){
	for(int i=1;i<=cnt3;i++){
		int maxn=-0x3f3f3f3f,idx=0;
		if(_3[i]==-1) continue;
		for(int j=1;j<=2;j++){
			if(maxn<-a[_3[i]][3]+a[_3[i]][j]){
				maxn=-a[_3[i]][3]+a[_3[i]][j];
				idx=j;
			}
		}
		b[i]={maxn,_3[i],idx,i};
	}
	sort(b+1,b+1+cnt3,cmp);
	int cnt=mp[3]-n/2;
	for(int i=1;i<=cnt;i++){
//		printf("值:%d 原数组下标:%d 到(1/2/3):%d\n",b[i].v,b[i].idx,b[i].to_);
		mp[b[i].to_]++;
		mp[3]--;
		_3[b[i].idxx]=-1;
		b[i].v=-0x3f3f3f3f;
		if(b[i].to_==2) _2[++cnt2]=b[i].idx;
		if(b[i].to_==1) _1[++cnt1]=b[i].idx;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		mp.clear();
		cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			int maxn=0,idx=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(maxn<a[i][j]){
					idx=j;
					maxn=a[i][j];
				}
			}
			if(idx==1) _1[++cnt1]=i;
			if(idx==2) _2[++cnt2]=i;
			if(idx==3) _3[++cnt3]=i;
			mp[idx]++;
		}
		while(1){
//			for(int i=1;i<=cnt1;i++) cout<<_1[i]<<' ';
//			cout<<'\n';
//			for(int i=1;i<=cnt2;i++) cout<<_2[i]<<' ';
//			cout<<'\n';
//			for(int i=1;i<=cnt3;i++) cout<<_3[i]<<' ';
//			cout<<'\n';
			if(mp[1]<=n/2&&mp[2]<=n/2&&mp[3]<=n/2) break;
			if(mp[1]>n/2) change_1();
			if(mp[2]>n/2) change_2();
			if(mp[3]>n/2) change_3();
		}
		int ans=0;
		for(int i=1;i<=cnt1;i++) if(_1[i]!=-1) ans+=a[_1[i]][1];
		for(int i=1;i<=cnt2;i++) if(_2[i]!=-1) ans+=a[_2[i]][2];
		for(int i=1;i<=cnt3;i++) if(_3[i]!=-1) ans+=a[_3[i]][3];
		cout<<ans<<'\n';
	}
	return 0;
}
