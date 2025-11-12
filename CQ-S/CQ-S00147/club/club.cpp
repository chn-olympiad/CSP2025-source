#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fre(X) freopen(X".in","r",stdin),freopen(X".out","w",stdout)
#define Xueli return
#define Chang 0
using namespace std;
namespace did{
	void init(){

	}
	int n;
	struct WZOI{
		int v,i,j;
	}a[100005][5];
	int now[100005];
	int cnt[5];
	int ans=0;
	bool cmp(WZOI x,WZOI y){
		return x.v>y.v;
	}
	bool cmpp(int j,int jj){
		return a[j][2].v-a[j][1].v>a[jj][2].v-a[jj][1].v;
	}
	void lusolve(){
		memset(cnt,0,sizeof(cnt));
		ans=0;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1].v>>a[i][2].v>>a[i][3].v;
			for(int j=1;j<=3;j++)a[i][j].i=i,a[i][j].j=j;
			sort(a[i]+1,a[i]+4,cmp);
			ans+=a[i][1].v;
			now[i]=a[i][1].j;
			cnt[a[i][1].j]++;
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>=n/2){
				vector<int> q(0);
				for(int j=1;j<=n;j++){
					if(now[j]==i){
						q.push_back(j);//大家都是按照第一志愿 
					}
				}
				sort(q.begin(),q.end(),cmpp);
				for(int jj=0;jj<q.size()-n/2;jj++){
					int j=q[jj];
					ans+=a[j][2].v-a[j][1].v;
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
}
signed main(){
	IOS();
	fre("club");
	int Q=1;
	cin>>Q;
	did::init();
	while(Q--)did::lusolve();
//while(1);
	Xueli Chang;
}
//1s 512MB
//0.1144s 13MB
/*
重要结论:不会出现两个同时出现满员 
Big Question
多测不清空,_____ 
*/
