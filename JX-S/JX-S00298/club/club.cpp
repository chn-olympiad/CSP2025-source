#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
struct p{
	int d1,d2,d3;
}a[N];
int maxs = -1,n;
void dfs(int x,int cnt1,int cnt2,int cnt3,int sum){
	if(x==n+1) maxs = max(maxs,sum);
	if(x>n) return;
	if(cnt1<n/2) dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x].d1);
	if(cnt2<n/2) dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x].d2);
	if(cnt3<n/2) dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x].d3);
}

bool cmp(p a,p b){
	return a.d1>b.d1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		bool f = 1;
		for(int i = 1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d2!=0 || a[i].d3!=0) f = 0;
		}
		if(n>10){
			if(f){
				sort(a+1,a+1+n,cmp);
				int cnt = 0;
				for(int i = 1;i<=n/2;i++){
					cnt+=a[i].d1;
				}
				cout<<cnt<<endl;
			}else{
				int cnt = 0;
				for(int i = 1;i<=n;i++){
					cnt+=(a[i].d1+a[i].d2+a[i].d3-max(a[i].d1,max(a[i].d2,a[i].d3))-min(a[i].d1,max(a[i].d2,a[i].d3)));
				}
				cout<<cnt<<endl;
			}
		}else{
			maxs = -1;
			dfs(1,0,0,0,0);
			cout<<maxs<<endl;	
		}
			
	}
	
	return 0;
}
