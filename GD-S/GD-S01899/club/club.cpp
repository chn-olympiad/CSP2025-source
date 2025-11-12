#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[100010][3];
inline int max(int a,int b){
	return a>b?a:b; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		priority_queue<int> q[3];
		ll s=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			s+=max(max(a[i][0],a[i][1]),a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				q[0].push(max(a[i][1],a[i][2])-a[i][0]);
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				q[1].push(max(a[i][0],a[i][2])-a[i][1]);
			}
			else{
				q[2].push(max(a[i][1],a[i][0])-a[i][2]);
			}
			
		}
		for(int i=0;i<3;i++){
			while(q[i].size()>n/2){
				s+=q[i].top();
				q[i].pop();
			}
		}
		cout<<s<<'\n';
	}
	return 0;
} 
