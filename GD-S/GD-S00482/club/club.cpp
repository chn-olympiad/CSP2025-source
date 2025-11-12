#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
struct node{
	ll a,b,c;
}p[N];
struct edge{
	ll fir,sec;
}q[N*10];
ll ans=0,n,dnt=0;
void dfs(int now,int cnt1,int cnt2,int cnt3,ll tot1,ll tot2,ll tot3){
	if(now==n+1){
		ans=max(ans,tot1+tot2+tot3);
		return;
	}
	if(cnt1<n/2)dfs(now+1,cnt1+1,cnt2,cnt3,tot1+p[now].a,tot2,tot3);
	if(cnt2<n/2)dfs(now+1,cnt1,cnt2+1,cnt3,tot1,tot2+p[now].b,tot3);
	if(cnt3<n/2)dfs(now+1,cnt1,cnt2,cnt3+1,tot1,tot2,tot3+p[now].c);
}
bool cmp(node &x,node &y){
	return x.a>y.a;
}
bool cmp2(edge &x,edge &y){
	return x.sec>y.sec;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(p[i].b!=0||p[i].c!=0)return false;
	}
	return true;
}
bool check2(){
	for(int i=1;i<=n;i++)if(p[i].c!=0)return false;
	return true;
}
int cnt1=0,cnt2=0,cnt3=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//freopen("club3.in","r",stdin);
	//freopen("ans.ans","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		if(check()){
			ans=0;
			sort(p+1,p+1+n,cmp);
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(cnt<n/2)ans+=p[i].a,cnt++;
				else break;
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(n<=10){
			ans=0;
			dfs(1,0,0,0,0,0,0);			
		}
		else{
			dnt=0;
			for(int i=1;i<=n;i++){
				q[++dnt].fir=1;q[dnt].sec=p[i].a;
				q[++dnt].fir=2;q[dnt].sec=p[i].b;
				q[++dnt].fir=3;q[dnt].sec=p[i].c;
			}
			sort(q+1,q+1+dnt,cmp2);
			for(int i=1;i<=dnt;i++){
				//最后5分钟想到了怎么打，但是打不完了。。。。 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*3
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
*/
