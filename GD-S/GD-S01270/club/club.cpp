#include<bits/stdc++.h>
#include<cstdio>
#include<queue>

#define int long long

using namespace std;

int t;
int n;
struct node{
	int a,b,c;
}a[100005];
priority_queue<int,vector<int>, greater<int> > q;
//值、编号
bool vis[100001]; 

void solve(){
	while(!q.empty())q.pop();
	for(int i = 1; i <= n; i ++ )vis[i] = 0;
	cin>>n;
	int ans,cnta,cntb,cntc;
	ans = cnta = cntb = cntc = 0;
	for(int i = 1; i <= n; i ++ ){
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].a >= a[i].b && a[i].a >= a[i].c){
			ans += a[i].a;
			cnta ++ ;
		}else if(a[i].b >= a[i].a && a[i].b >= a[i].c){
			ans += a[i].b;
			cntb ++ ;
		}else if(a[i].c >= a[i].b && a[i].c >= a[i].b){
			ans += a[i].c;
			cntc ++ ;
		}
	}
//	cout<<cnta<<" "<<cntb<<" "<<cntc<<"\n";
	//知道了每一种应该分到哪个组里 
	int w = 0;
	if(cnta > n/2){//分a最多
		w = cnta;
		for(int i = 1; i <= n; i ++ ){
			if(a[i].a >= a[i].b && a[i].a >= a[i].c){
				q.push(min(a[i].a-a[i].b,a[i].a-a[i].c));
			} 
		}
	}
	if(cntb > n/2){//分b最多 
		w = cntb;
		for(int i = 1; i <= n; i ++ ){
			if(a[i].b >= a[i].a && a[i].b >= a[i].c){
				q.push(min(a[i].b-a[i].a,a[i].b-a[i].c));
			} 
		}
	}
	if(cntc > n/2){//分c最多 
		w = cntc;
		for(int i = 1; i <= n; i ++ ){
			if(a[i].c >= a[i].a && a[i].c >= a[i].b){
				q.push(min(a[i].c-a[i].a,a[i].c-a[i].b));
			} 
		}
	}
//	cout<<w<<"\n";
	for(int i = 1; i <= w - n/2; i ++ ){
		ans -= q.top();
		q.pop();
	}
	cout<<ans<<"\n";
	return ;
} 

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t -- ){
		solve();
	}
} 
/* 
1
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

9953 - 3195。 
*/ 
