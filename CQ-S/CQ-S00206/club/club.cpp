#include<bits/stdc++.h>
using namespace std;
int t,n,p[4];
pair<int,int>a[100005][4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        p[1]=p[2]=p[3]=0;
        int ans=0;
		priority_queue<int,vector<int>,greater<int>>q[4];
        for(int i=1;i<=n;i++){
        	for(int j=1;j<=3;j++){
        		cin>>a[i][j].first;
        		a[i][j].second=j;
			}
			sort(a[i]+1,a[i]+4,greater<pair<int,int>>());
			p[a[i][1].second]++;
			ans+=a[i][1].first;
			q[a[i][1].second].push(a[i][1].first-a[i][2].first);
        }
        for(int i=1;i<=3;i++){
        	if(p[i]>n/2){
        		while(q[i].size()>n/2){
        			int x=q[i].top();
        			ans-=x;
        			q[i].pop();
				}
			}
		}
		cout<<ans<<"\n";
    }
    return 0;
}
