#include<bits/stdc++.h>
using namespace std;
namespace cs{
	#define LL long long
	#define fir first
	#define sec second
	typedef pair<int,int> PII;
	const int N=1e5;
	const int INF=2e9;
	int T,n,bestc[N+5],cnt[5],bcnt,ov;
	LL a[N+5][5],ans,b[N+5];
	void Init(){
		cnt[1]=cnt[2]=cnt[3]=0;
		bcnt=0;
		ans=0;
	}
	int main(){
		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cin>>T;
		int ma;
		while(T--){
			Init();
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				ma=max({a[i][1],a[i][2],a[i][3]});
				if(ma==a[i][1]) bestc[i]=1;
				else if(ma==a[i][2]) bestc[i]=2;
				else bestc[i]=3;
				cnt[bestc[i]]++;
				ans+=a[i][bestc[i]];
			}
			if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
				cout<<ans<<"\n";
				continue;
			}
			if(cnt[1]>n/2) ov=1;
			else if(cnt[2]>n/2) ov=2;
			else ov=3;
			for(int i=1;i<=n;i++){
				if(bestc[i]==ov){
					++bcnt;
					b[bcnt]=a[i][bestc[i]];
					a[i][bestc[i]]=-1;
					b[bcnt]-=max({a[i][1],a[i][2],a[i][3]});
				}
			}
			sort(b+1,b+bcnt+1);
			for(int i=1;i<=cnt[ov]-n/2;i++){
				ans-=b[i];
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
}
int main(){
	cs::main();
	return 0;
}
/*
怎么又是贪心 
0min 解压文件，密码：Ren5Jie4Di4Ling5% 
12min 写完 T1 
214min 开始对拍 T1 
233min 结束 T1 的对拍，共拍数据 18164 组 
*/
