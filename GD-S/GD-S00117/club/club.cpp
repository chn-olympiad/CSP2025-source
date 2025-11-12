#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct s{long long a,b,c;
}x[100005];
vector<long long> u,v,w;
priority_queue<long long,vector<long long>,greater<long long>> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		u.clear(),v.clear(),w.clear();
		q=priority_queue<long long,vector<long long>,greater<long long>>();
		cin>>n;
		for(long long i=1;i<=n;i++)cin>>x[i].a>>x[i].b>>x[i].c;
		for(long long i=1;i<=n;i++){
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c)u.push_back(i),ans+=x[i].a;
			else if(x[i].b>=x[i].a&&x[i].b>=x[i].c)v.push_back(i),ans+=x[i].b;
			else w.push_back(i),ans+=x[i].c;
		}
		if(u.size()>n/2){
			for(auto i:u){
				long long t=min(x[i].a-x[i].b,x[i].a-x[i].c);
				q.push(t);
			}
			for(long long i=u.size();i>n/2;i--){
				ans-=q.top();
				q.pop();
			}
		}else if(v.size()>n/2){
			for(auto i:v){
				long long t=min(x[i].b-x[i].a,x[i].b-x[i].c);
				q.push(t);
			}
			for(long long i=v.size();i>n/2;i--){
				ans-=q.top();
				q.pop();
			}
		}else if(w.size()>n/2){
			for(auto i:w){
				long long t=min(x[i].c-x[i].b,x[i].c-x[i].a);
				q.push(t);
			}
			for(long long i=w.size();i>n/2;i--){
				ans-=q.top();
				q.pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
