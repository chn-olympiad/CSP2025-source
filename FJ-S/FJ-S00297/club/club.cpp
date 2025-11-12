#include<bits/stdc++.h>
using namespace std;
int T,n,i,x,y,z,w,ans;
priority_queue<int>pq1,pq2,pq3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		while(!pq1.empty())pq1.pop();
		while(!pq2.empty())pq2.pop();
		while(!pq3.empty())pq3.pop();
		for(i=1;i<=n;i++){
			cin>>x>>y>>z;
			w=max(x,max(y,z));
			if(w==x)pq1.push(max(y,z)-w);
			else if(w==y)pq2.push(max(x,z)-w);
			else pq3.push(max(x,y)-w);
			ans+=w;
		}
		if(pq1.size()>n/2){
			while(pq1.size()>n/2)ans+=pq1.top(),pq1.pop();
		}
		else if(pq2.size()>n/2){
			while(pq2.size()>n/2)ans+=pq2.top(),pq2.pop();
		}
		else if(pq3.size()>n/2){ 
			while(pq3.size()>n/2)ans+=pq3.top(),pq3.pop();
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
