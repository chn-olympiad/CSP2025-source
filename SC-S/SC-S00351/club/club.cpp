#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct people{
	int id,v;
	friend bool operator <(const people &a,const people &b){
		return a.v<b.v;
	}
};
int n,a[N][3];
namespace sub2{//n=4/10,subtask #2,#3,#4
	int dfs(int now,int cnt0,int cnt1,int cnt2,int ans){
		if(now>n) return ans;
		int ret=0;
		if(cnt0*2<n) ret=max(ret,dfs(now+1,cnt0+1,cnt1,cnt2,ans+a[now][0]));
		if(cnt1*2<n) ret=max(ret,dfs(now+1,cnt0,cnt1+1,cnt2,ans+a[now][1]));
		if(cnt2*2<n) ret=max(ret,dfs(now+1,cnt0,cnt1,cnt2+1,ans+a[now][2]));
		return ret;
	}
	int main(void){
		cout<<dfs(1,0,0,0,0)<<endl;
		return 0;
	}
}
namespace sub3{// A,subtask #12
	int l[N];
	int main(void){
		memset(l,0,sizeof(l));
		for(int i=1;i<=n;i++) l[i]=a[i][0];
		sort(l+1,l+n+1);
		int ans=0;
		for(int i=1;i<=n/2;i++) ans+=l[i];
		cout<<ans<<endl;
		return 0;
	}
}
namespace sub4{// n=200 subtask #9-11
	int f[205][105][105];
	int main(void){
		memset(f,0,sizeof(f));
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i&&2*j<=n;j++){
				for(int k=0;j+k<=i&&2*k<=n;k++){
					int l=i-j-k;
					if(2*l>n) continue;
					f[i][j][k]=max({
						(j==0?0:f[i-1][j-1][k]+a[i][0]),
						(k==0?0:f[i-1][j][k-1]+a[i][1]),
						(l==0?0:f[i-1][j][k]+a[i][2])
					});
					ans=max(ans,f[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
}
namespace sub5{
	struct worker{
		int id,cl,cos;
		friend bool operator <(const worker &i,const worker &j){
			return i.cos<j.cos;
		}
	};
	priority_queue<worker> q;
	int cnt0=0,cnt1=0,ans=0;
	int main(void){
		ans=cnt0=cnt1=0;q=priority_queue<worker>();
		for(int i=1;i<=n;i++){
			ans+=max(a[i][0],a[i][1]);
			q.push({i,(a[i][0]>a[i][1]?1:0),abs(a[i][0]-a[i][1])});
		}
		for(int i=1;i<=n;i++){
			if(2*cnt0==n){
				if(q.top().cl==1)ans-=q.top().cos;
				cnt1++;
				q.pop();
			}else if(2*cnt1==n){
				if(q.top().cl==0) ans-=q.top().cos;
				cnt0++;
				q.pop();
			}else{
				if(q.top().cl==0) cnt1++;
				else cnt0++;
				q.pop();
			}
		}
		cout<<ans<<endl;
		return 0;
	}
}
//namespace sub6{
//	struct worker{
//		int id,a;
//		friend bool operator <(const worker &x,const worker &y){
//			return x.a>y.a;
//		}
//	};
//	int to[N];//记录去向
//	int cnt[3]={0};//记录各部门员工数量 
//	porority_queue<int> q[3][3];
//	int main(void){
//		memset(to,-1,sizof(to));
//		cnt[0]=cnt[1]=cnt[2]=0;
//		for(auto &i:q) for(auto &j:i) j.clear();
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<3;j++)
//				for(int k=0;k<3;k++)
//					while(to[q[j][k].top()]!=j)
//						q[j][k].pop();
//			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
//				//考虑进入0部门
//				if(2*cnt[0]<n){//还可以进入 
//					q[0][0].push({i,a[i][0]});
//					q[0][1].push({i,a[i][1]});
//					q[0][2].push({i,a[i][2]});
//				}else{//满员啦，重新（悲） 
//					//做不出来，全部毁灭 
//					//高一学竞赛打成这样也真**该退役了 
//				}
//			}
//		}
//		return 0;
//	}
//}
int rmain(void){
	memset(a,0,sizeof(a));
	cin>>n;
	bool flag[2]={true,true};
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][1]!=0) flag[0]=false;
		if(a[i][2]!=0) flag[1]=false;
	}
	if(n==2) cout<<max({a[1][0]+max(a[2][1],a[2][2]),a[1][1]+max(a[2][0],a[2][2]),a[1][2]+max(a[2][0],a[2][1])})<<endl;
	else if(n==4||n==10){
		sub2::main();
		return 0;
	}else if(flag[0]){
		sub3::main();
		return 0;
	}else if(n<=200){
		sub4::main();
		return 0;
	}else if(flag[1]){
		sub5::main();
		return 0;
	}else while(1);//我真的没招了，一起毁灭吧 
	return 0;
}
int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--) rmain();
	return 0;
} 
//Not want to solve it at all!!!!
//Is it a green problem??????????on T1?????????????
//I want to say some thing bad!!**** ** ****;
//I want to give up(sad);
//If no 1=,I have to AFO;
//Luogu:921880 2022xsj
//%%kkksc03%%
//T1手写4000多字符么 真**有点意思 退役吧全部毁灭吧
//是T1就**乖乖给老子AC啊啊啊啊啊啊啊啊啊
//距离考试结束还剩余约1h：头有点晕了，三瓶乐虎就是得劲
//freopen
//freopen 反正就那样了，搞搞诈骗怎么了 
//Luogu:921880 2022xsj
//lovewyr 
//Excepted:75pts