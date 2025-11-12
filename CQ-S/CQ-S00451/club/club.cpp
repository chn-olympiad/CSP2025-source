#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100005][5];
int t[5][100005];
int h[5],id,mx,mx2;
long long ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		h[1]=0,h[2]=0,h[3]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			id=-1,mx=-1,mx2=-1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>mx){
					mx2=mx;
					mx=a[i][j],id=j;
				}else{
					mx2=max(mx2,a[i][j]);
				}
			}
			ans+=mx;
			h[id]++;
			t[id][h[id]]=mx-mx2;
		}
		id=-1;
		for(int i=1;i<=3;i++){
			if(h[i]>n/2){
				id=i;
			}
		}
		if(id!=-1){
			stable_sort(t[id]+1,t[id]+h[id]+1);
			for(int i=1;i<=h[id]-n/2;i++){
				ans-=t[id][i];
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}
