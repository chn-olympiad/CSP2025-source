#include<bits/stdc++.h>
#define int long long
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,T,f[N][5];
struct node{
	int a,b,c;
}a[N];
priority_queue<int> q1,q2,q3;
signed main(){
	qwq;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		while(q1.size())q1.pop();
		while(q2.size())q2.pop();
		while(q3.size())q3.pop();
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				q1.push(max(a[i].b,a[i].c)-a[i].a);
				ans+=a[i].a;
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				q2.push(max(a[i].a,a[i].c)-a[i].b);
				ans+=a[i].b;
			}
			else{
				q3.push(max(a[i].a,a[i].b)-a[i].c);
				ans+=a[i].c;
			}
		}
		while(q1.size()>n/2){
			ans+=q1.top();
			q1.pop();
		}
		while(q2.size()>n/2){
			ans+=q2.top();
			q2.pop();
		}
		while(q3.size()>n/2){
			ans+=q3.top();
			q3.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//14:58 wo tai cai le qwq
