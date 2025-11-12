#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pa pair<int,int>
#define mkp make_pair
#define FI first
#define SE second 
priority_queue<int> qa,qb,qc; 
int t,n,a[100005],b[100005],c[1000005],ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		while(qa.size())qa.pop();
		while(qb.size())qb.pop();
		while(qc.size())qc.pop();
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=max(b[i],c[i])){
				qa.push(max(b[i],c[i])-a[i]);
				ans+=a[i];
			}else if(b[i]>=max(a[i],c[i])){
				qb.push(max(a[i],c[i])-b[i]);
				ans+=b[i];
			}else{
				qc.push(max(a[i],b[i])-c[i]);
				ans+=c[i];
			}
		}
		while(qa.size()>n/2){
			ans+=qa.top();
			qa.pop();
		}
		while(qb.size()>n/2){
			ans+=qb.top();
			qb.pop();
		}
		while(qc.size()>n/2){
			ans+=qc.top();
			qc.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}  

