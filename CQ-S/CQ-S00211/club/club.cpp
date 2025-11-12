#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010][5];

priority_queue<int,vector<int>,greater<int>> pq;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		}
		ll ans=0;
		int tj1=0,tj2=0,tj3=0;
		pq=priority_queue<int,vector<int>,greater<int>>();
		for(int i=1;i<=n;i++){
			int t=max({a[i][1],a[i][2],a[i][3]});
			ans+=t;
			if(t==a[i][1]){
				tj1++;
			}else if(t==a[i][2]){
				tj2++;
			}else{
				tj3++;
			}
		}
		if(max({tj1,tj2,tj3})>n/2){
			int t=max({tj1,tj2,tj3});
			int t2;
			if(tj1==t){
				t2=1;
			}else if(tj2==t){
				t2=2;
			}else{
				t2=3;
			}
			for(int i=1;i<=n;i++){
				int t=max({a[i][1],a[i][2],a[i][3]});
				if(t==a[i][t2]){
					if(t2==1){
						pq.push(a[i][t2]-max(a[i][2],a[i][3]));
					}else if(t2==2){
						pq.push(a[i][t2]-max(a[i][1],a[i][3]));
					}else{
						pq.push(a[i][t2]-max(a[i][1],a[i][2]));
					}
				}
			}
		}
		while(max({tj1,tj2,tj3})>n/2){
			int t=max({tj1,tj2,tj3});
			int t2;
			if(tj1==t){
				t2=1;
			}else if(tj2==t){
				t2=2;
			}else{
				t2=3;
			}
			ans-=pq.top();
			pq.pop();
			if(t2==1){
				tj1--;
			} else if(t2==2){
				tj2--;
			}else{
				tj3--;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
