#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[100005][5],ans;
void dfs(int x,int num,int cnt1,int cnt2,int cnt3,int sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	sum+=a[x][num];
	if(cnt1<n/2){
		dfs(x+1,1,cnt1+1,cnt2,cnt3,sum);
	}
	if(cnt2<n/2){
		dfs(x+1,2,cnt1,cnt2+1,cnt3,sum);
	}
	if(cnt3<n/2){
		dfs(x+1,3,cnt1,cnt2,cnt3+1,sum);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		bool b=0;
		vector<int>x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j!=1){
					if(a[i][j]!=0){
						b=1;
					}
				}else{
					x.push_back(a[i][j]);
				}
			}
		}
		if(!b){
			sort(x.begin(),x.end());
			for(int i=x.size()-1;i>=n/2;i--){
				ans+=x[i];
			}
			cout<<ans<<"\n";
			break;
		}
	    dfs(1,1,1,0,0,0);
	    dfs(1,2,0,1,0,0);
	    dfs(1,3,0,0,1,0);
	    cout<<ans<<"\n";
	}
	return 0;
}
/*
  tttttttttttttttttt
ttttttttttttttttttttttt
ttttttttttttttttttttttt
ttttt                tt
ttt                  tt
tt    tttttt   tt  tttttt
ttttttt    tttt  ttt    t
tt    ttttt        tttttt
tt             t     tt
tt            tt     tt
tt                   tt
tt       ttttttttt   tt
tt                   tt
ttttttttttttttttttttttt

*/