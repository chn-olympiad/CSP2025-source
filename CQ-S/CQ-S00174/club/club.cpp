#include<bits/stdc++.h>
#define x first
#define id second
using namespace std;
const int N=1e5+3;
struct A{
	int cnt[3];
	bool operator < (const A&q)const{
		if(q.cnt[0]==cnt[0]){
			if(q.cnt[1]==cnt[1])	return q.cnt[2]>cnt[2];
			return q.cnt[1]>cnt[1];
		}
		return q.cnt[0]>cnt[0];
	}
}a[N];
int t,n,c[3],ans,f[N];
priority_queue<pair<int,int> > h; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof f);
		ans=0;
		c[0]=c[1]=c[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)	cin>>a[i].cnt[j];
		}
		for(int j=0;j<3;j++){
			for(int i=1;i<=n;i++){
				if(!f[i])	h.push({a[i].cnt[j],i});
			}
			for(int i=1;i<=n/2;){
				if(h.empty())	break;
				int j2=min(j+1,2);
				if(h.top().x<a[h.top().id].cnt[j2]||h.top().x<a[h.top().id].cnt[2]){
					h.pop();
					continue;
				}
				ans+=h.top().x;
//				cout<<h.top().x<<"\n";
				i++;
				f[h.top().id]=1;
				h.pop();
			}
			while(h.size())	h.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}

