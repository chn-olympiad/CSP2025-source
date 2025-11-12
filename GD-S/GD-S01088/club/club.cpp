#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T;
ll n,a[100005],b[100005],c[100005];
ll nowa,nowb,nowc,sum,ans;
void dfs(int k){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	if(nowa<n/2){
		nowa++;
		sum+=a[k];
		dfs(k+1);
		sum-=a[k];
		nowa--;
	}
	if(nowb<n/2){
		nowb++;
		sum+=b[k];
		dfs(k+1);
		sum-=b[k];
		nowb--;
	}
	if(nowc<n/2){
		nowc++;
		sum+=c[k];
		dfs(k+1);
		sum-=c[k];
		nowc--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		ll temp=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i]; 
			temp+=b[i]+c[i];
		}
		if(temp==0){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--){
				ans+=a[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}/*
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
*/ 
