//club
#include<bits/stdc++.h>
using namespace std;
#define LOCAL
//#define int long long
#define emdl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=1e5+5;
const int MAXM=3+2;
struct node{
	int a,b,c;
	int num1,num2,num3;
	int ch;
};

int n;
node a[MAXN];
int sum[MAXM];
void solve(){
	int m=3;
	sum[1]=sum[2]=sum[3]=0;
	int ans=0;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int maxx,max_id;
		int b[MAXM];
		for(int j=1;j<=m;j++) cin>>b[j];
		a[i].a=b[1];a[i].b=b[2];a[i].c=b[3];
		
		maxx=-1;
		max_id=0;
		for(int j=1;j<=m;j++){
			if(b[j]>maxx){
				maxx=b[j];
				max_id=j;
			}
		}
		
		a[i].num1=maxx;
		ans+=a[i].num1;
		sum[max_id]++;
		b[max_id]=-1;
		a[i].ch=max_id;
		
		maxx=-1;
		max_id=0;
		for(int j=1;j<=m;j++){
			if(b[j]>maxx){
				maxx=b[j];
				max_id=j;
			}
		}
		
		a[i].num2=maxx;
		b[max_id]=-1;
		
		maxx=-1;
		max_id=0;
		for(int j=1;j<=m;j++){
			if(b[j]>maxx){
				maxx=b[j];
				max_id=j;
			}
		}
		
		a[i].num3=maxx;
		b[max_id]=-1;
	}
	
	for(int k=1;k<=m;k++){
		if(sum[k]>n/2){
			int cnt=sum[k]-n/2;
			priority_queue<int,vector<int>,greater<int>> res;
			
			for(int i=1;i<=n;i++){
				if(a[i].ch==k){
					res.push(a[i].num1-a[i].num2);
				}
			}
			
			for(int i=1;i<=cnt;i++){
				int top=res.top();
				res.pop();
				ans-=top;
			}
			
			break;
		}
	}
	
	cout<<ans<<emdl;
	
	return;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef LOCAL
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
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
*/
