#include<bits/stdc++.h>
#define pii pair<int, int> 
#define st first
#define nd second
using namespace std;
int read(){
	int x=0, f=1;
	char ch=getchar();
	for(ch;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(ch;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;	
}
constexpr int INF=1e9, N=1e5+5;
int T, n, x1=1, x2=1, x3=1, ans, cnt[4], pre[N];
pii a1[N], a2[N], a3[N]; // 第一维存满意度, 第二维存编号 
bool used[N];
inline void clear(){
	cnt[1]=cnt[2]=cnt[3]=0;
	ans=0;
	x1=x2=x3=1;
	memset(used, 0, sizeof(used));
}
int cur, cnt1, cnt2, cnt3;
void dfs(int x){
	if(x==n+1) return ans=max(ans, cur), void();
	if(cur+pre[n]-pre[x-1]<=ans) return;
	if(cnt1+1<=n/2){
		cnt1++;
		cur+=a1[x].st;
		dfs(x+1);
		cnt1--;
		cur-=a1[x].st;	
	}
	if(cnt2+1<=n/2){
		cnt2++;
		cur+=a2[x].st;
		dfs(x+1);
		cnt2--;
		cur-=a2[x].st;	
	}
	if(cnt3+1<=n/2){
		cnt3++;
		cur+=a3[x].st;
		dfs(x+1);
		cnt3--;
		cur-=a3[x].st;	
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T=read();
	for(int i=1;i<=T;i++, clear()){
		n=read();
		bool flag2=1, flag3=1;
		for(int i=1;i<=n;i++){
			a1[i].st=read(), a2[i].st=read(), a3[i].st=read();
			a1[i].nd=a2[i].nd=a3[i].nd=i;
			if(a2[i].st!=0) flag2=0;
			if(a3[i].st!=0) flag3=0;
			pre[i]=pre[i-1]+max(max(a1[i].st, a2[i].st), a3[i].st);	
		}
		if(flag2 && flag3){
			sort(a1+1, a1+1+n, greater<>());
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=a1[i].st;
			cout<<ans<<'\n';
			continue;	
		}
		if(n<=200){
			dfs(1);
			cout<<ans<<'\n';
			continue;
		}
		sort(a1+1, a1+1+n, greater<>());
		sort(a2+1, a2+1+n, greater<>());
		sort(a3+1, a3+1+n, greater<>());
		while(x1<=n || x2<=n || x3<=n){
			if(cnt[1]>=n/2) x1=n+1;
			if(cnt[2]>=n/2) x2=n+1;
			if(cnt[3]>=n/2) x3=n+1;
			int p1=a1[x1].st, p2=a2[x2].st, p3=a3[x3].st;
			if(p1>=p2 && p1>=p3){
				used[a1[x1].nd]=1, x1++;
				ans+=p1;
				cnt[1]++;
			}else if(p2>=p1 && p2>=p3){
				used[a2[x2].nd]=1, x2++;
				ans+=p2;
				cnt[2]++;
			}else{
				used[a3[x3].nd]=1, x3++;
				ans+=p3;
				cnt[3]++;
			}
			while(x1<=n && used[a1[x1].nd]) x1++;
			while(x2<=n && used[a2[x2].nd]) x2++;
			while(x3<=n && used[a3[x3].nd]) x3++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
