#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
#define fo(i,n,m)	for(int i=n;i<=m;i++)
#define foo(i,n,m)	for(int i=n;i>=m;i--)
int n;
struct Node{
	int a1,a2,a3;
} q[maxn];
int ans; 
bool cmp(Node A,Node B){
	bool f1=(A.a1&&A.a2)||(A.a2&&A.a3)||(A.a1&&A.a3);
	bool f2=(B.a1&&B.a2)||(B.a2&&B.a3)||(B.a1&&B.a3);
	if(f1&&!f2)	return f1>f2;
	else if(!f1&&f2)	return f2>f1;
	return max(A.a1,max(A.a2,A.a3))>max(B.a1,max(B.a2,B.a3));
}
bool cmp_apts(Node x,Node y){
	return x.a1>y.a1;
}
void dfs(int x,int a,int b,int c,int cnt1,int cnt2,int cnt3){
	if(x==n+1){
		ans=max(ans,(a+b+c));
	}
	if(cnt1+1<=n/2)
		dfs(x+1,a+q[x].a1,b,c,cnt1+1,cnt2,cnt3);
	if(cnt2+1<=n/2)
		dfs(x+1,a,b+q[x].a2,c,cnt1,cnt2+1,cnt3);
	if(cnt3+1<=n/2)
		dfs(x+1,a,b,c+q[x].a3,cnt1,cnt2,cnt3+1);
	return ;
}
void adddddd(int i,int maxi1){
	if(maxi1==1){
		ans+=q[i].a1;
	}else if(maxi1==2){
		ans+=q[i].a2;
	}else{
		ans+=q[i].a3;
	}
}
void solve(){
	cin>>n;
	int cnta=0,cntb=0,cntc=0; 
	bool Apts=1;
	fo(i,1,n){
		cin>>q[i].a1>>q[i].a2>>q[i].a3;
		cnta+=q[i].a1;
		cntb+=q[i].a2;
		cntc+=q[i].a3;
		Apts=(Apts&&(!q[i].a2&&!q[i].a3));
	}
	ans=0;
	if(Apts){	//b==0,c==0; 5pts
		sort(q+1,q+1+n,cmp_apts);
		fo(i,1,n/2){
			ans+=q[i].a1;
		}
		cout<<ans<<'\n';
		return ;
	}else if(n<=10){	//20pts
		dfs(1,0,0,0,0,0,0);
		cout<<ans<<'\n';
		return ;
	}
	sort(q+1,q+1+n,cmp);
	ans=0;
	int cnt[4]={};
	fo(i,1,n){
		int maxxx1=max(q[i].a1,max(q[i].a2,q[i].a3));
		int maxi1,maxi2,maxi3;
		if(maxxx1==q[i].a1){
			maxi1=1;
			maxxx1=max(q[i].a2,q[i].a3);
			if(maxxx1==q[i].a2){
				maxi2=2;
				maxi3=3;
			} else{
				maxi2=3;
				maxi3=2;
			}
		}else if(maxxx1==q[i].a2){
			maxi1=2;
			maxxx1=max(q[i].a1,q[i].a3);
			if(maxxx1==q[i].a1){
				maxi2=1;
				maxi3=3;
			} else{
				maxi2=3;
				maxi3=1;
			}
		}else{
			maxi1=3;
			maxxx1=max(q[i].a1,q[i].a2);
			if(maxxx1==q[i].a1){
				maxi2=1;
				maxi3=2;
			} else{
				maxi2=2;
				maxi3=1;
			}
		}
		if(cnt[maxi1]<n/2){
			cnt[maxi1]++;
			adddddd(i,maxi1);
		}else{
			if(cnt[maxi2]<n/2){
				cnt[maxi2]++;
				adddddd(i,maxi2);
			}else if(cnt[maxi3]<n/2){
				cnt[maxi3]++;
				adddddd(i,maxi3);
			}
		}
	}
	cout<<ans<<'\n';
	return ; 
}
/*
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

147325

134782
*/
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int __;
	cin>>__;
	while(__--){
		solve();
	} 
	return 0;
}

