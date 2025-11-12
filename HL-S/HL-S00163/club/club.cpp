#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct ST{
	int a,b,c;
}t[N];
bool cmp(ST x,ST y){
	return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(t,0,sizeof t);
		int n,cnt1=0,cnt2=0,cnt3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>t[i].a>>t[i].b>>t[i].c,ans+=max(t[i].a,max(t[i].b,t[i].c));
		sort(t+1,t+n+1,cmp);
 		for(int i=1;i<=n;i++){
			if(max(t[i].a,max(t[i].b,t[i].c))==t[i].a) cnt1++;
			else if(max(t[i].a,max(t[i].b,t[i].c))==t[i].b) cnt2++;
			else cnt3++;
		}
		if(cnt1>n/2){
			priority_queue<int,vector<int>,greater<int> >q;
			for(int i=1;i<=n;i++){
				if(t[i].a!=max(t[i].a,max(t[i].b,t[i].c))) continue;
				int x=min(t[i].a-t[i].b,t[i].a-t[i].c);
				q.push(x);				
			}
			while(cnt1>n/2){
				ans-=q.top();
				q.pop();
				cnt1--;
			}
		}
		else if(cnt2>n/2){
			priority_queue<int,vector<int>,greater<int> >q;
			for(int i=1;i<=n;i++){
				if(t[i].b!=max(t[i].a,max(t[i].b,t[i].c))) continue;
				int x=min(t[i].b-t[i].a,t[i].b-t[i].c);
				q.push(x);				
			}
			while(cnt2>n/2){
				ans-=q.top();
				q.pop();
				cnt2--;
			}
		}
		else if(cnt3>n/2){
			priority_queue<int,vector<int>,greater<int> >q;
			for(int i=1;i<=n;i++){
				if(t[i].c!=max(t[i].a,max(t[i].b,t[i].c))) continue;
				int x=min(t[i].c-t[i].b,t[i].c-t[i].a);
				q.push(x);				
			}
			while(cnt3>n/2){
				ans-=q.top();
				q.pop();
				cnt3--;
			}
		}
		cout<<ans<<"\n";
	}
} 
/*
ÎÒÓÀÔ¶Ï²»¶Ï²¶à´¨º£ÃÎ 
*/
