#include<bits/stdc++.h>
#define int long long 
#define rep(i,a,b)	for(int i = (a);i<=(b);i++)
#define lep(i,a,b)	for(int i = (a);i>=(b);i--)
using namespace std;

const int N = 2e5+10;
int n,a[N][6],ans;

priority_queue<int,vector<int>,less<int> > q1,q2,q3;

inline void solve(){
	cin>>n;
	rep(i,1,n)	rep(j,1,3)	cin>>a[i][j];
	ans = 0;
	rep(i,1,n){
		if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
			if((int)q1.size()<n/2){
				q1.push(-a[i][1]+max(a[i][2],a[i][3]));
				ans+=a[i][1];
			}	
			else{
				if(max(a[i][2],a[i][3])<q1.top()+a[i][1]){
					ans+=q1.top();
					q1.pop();
					q1.push(-a[i][1]+max(a[i][2],a[i][3]));
					ans+=a[i][1];
				}
				else{
					ans+=max(a[i][2],a[i][3]);
				}
			}
		}
		else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
			if((int)q2.size()<n/2){
				q2.push(-a[i][2]+max(a[i][1],a[i][3]));
				ans+=a[i][2];
			}	
			else{
				if(max(a[i][1],a[i][3])<q2.top()+a[i][2]){
					ans+=q2.top();
					q2.pop();
					q2.push(-a[i][2]+max(a[i][1],a[i][3]));
					ans+=a[i][2];
				}
				else{
					ans+=max(a[i][1],a[i][3]);
				}
			}
		}
		else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
			if((int)q3.size()<n/2){
				q3.push(-a[i][3]+max(a[i][1],a[i][2]));
				ans+=a[i][3];
			}	
			else{
				if(max(a[i][1],a[i][2])<q3.top()+a[i][3]){
					ans+=q3.top();
					q3.pop();
					q3.push(-a[i][3]+max(a[i][1],a[i][2]));
					ans+=a[i][3];
				}
				else{
					ans+=max(a[i][1],a[i][2]);
				}
			}
		}
	}
	cout<<ans<<"\n";
	while(q1.size())	q1.pop();
	while(q2.size())	q2.pop();
	while(q3.size())	q3.pop();
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int T;	cin>>T;
	while(T--)	solve();
	return 0;
}
