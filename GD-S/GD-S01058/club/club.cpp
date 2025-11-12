#include<bits/stdc++.h>
using namespace std;
int n,a[100001][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		queue<int> q[4];
		cin>>n;
		int ans=0,k=n/2;
		for(int i=1;i<=n;i++){
			int mx=0,l1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>mx) {
					l1=j;
					mx=a[i][j];
				}
			}
			ans+=mx;
			q[l1].push(i);
		}
		for(int i=1;i<=3;i++){
			if(q[i].size()>k){
				int m=q[i].size()-k,t[100001];
				for(int j=1;j<=q[i].size();j++){
					int tmp=q[i].front();
					q[i].pop();
					if(i==1){
						t[j]=min(a[tmp][1]-a[tmp][2],a[tmp][1]-a[tmp][3]);
					}else if(i==2){
						t[j]=min(a[tmp][2]-a[tmp][1],a[tmp][2]-a[tmp][3]);
					}else{
						t[j]=min(a[tmp][3]-a[tmp][2],a[tmp][3]-a[tmp][1]);
					}
				}
				sort(t+1,t+q[i].size()+1);
				for(int i=1;i<=m;i++){
					ans-=t[i];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
