#include<bits/stdc++.h>
#define ll long long
using namespace std;
class stu{
public:
	ll fir,sec,thi,num;
}a[100005],f[100005][5];
ll t,n,MaxStu,ans;
void dfs(ll u,ll A,ll B,ll C,ll sum){
	if(u>=n){
		ans=max(ans,sum);
		return;
	}
	if(A<MaxStu) dfs(u+1,A+1,B,C,sum+a[u].fir);
	if(B<MaxStu) dfs(u+1,A,B+1,C,sum+a[u].sec);
	if(C<MaxStu) dfs(u+1,A,B,C+1,sum+a[u].thi);
	return;
}
bool cmp(stu a,stu b){
	return a.fir>b.fir || (a.fir==b.fir && a.sec>b.sec) || (a.fir==b.fir && a.sec==b.sec && a.thi>b.thi);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		cin>>n;
		MaxStu=n>>1;
		if(n<=16){
			for(ll i=0;i<n;i++){
				cin>>a[i].fir>>a[i].sec>>a[i].thi;
			}
			ans=0;
			dfs(0,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		for(ll i=1;i<=n;i++){
			cin>>a[i].fir>>a[i].sec>>a[i].thi;
		}
		memset(f,0,sizeof f);
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				stu it;
				it.num=-1;
				for(int k=1;k<3;k++){
					if(f[i-1][k].num>it.num && ((j==1 && f[i-1][k].fir<MaxStu) || (j==2 && f[i-1][k].sec<MaxStu) || (j==3 && f[i-1][k].thi<MaxStu))){
						it=f[i-1][k];
					}
				}
				if(it.num==-1) it.num=0;
				if(j==1){
					f[i][j].num=it.num+a[i].fir;
					f[i][j].fir=it.fir+1;
					f[i][j].sec=it.sec;
					f[i][j].thi=it.thi;
				}
				else if(j==2){
					f[i][j].num=it.num+a[i].sec;
					f[i][j].fir=it.fir;
					f[i][j].sec=it.sec+1;
					f[i][j].thi=it.thi;
				}
				else{
					f[i][j].num=it.num+a[i].thi;
					f[i][j].fir=it.fir;
					f[i][j].sec=it.sec;
					f[i][j].thi=it.thi+1;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cout<<f[i][j].num<<" ";
//			}
//			cout<<"\n";
//		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i].fir<<" "<<a[i].sec<<" "<<a[i].thi<<"\n";
//		}
		cout<<max(f[n][1].num,max(f[n][2].num,f[n][3].num))<<"\n";
	}
	return 0;
}
/*
你看到这段代码了？ 
你应该明白它是 __面向数据__(试图用 Markdown)的吧...
祝你好运，rp++;
*/
