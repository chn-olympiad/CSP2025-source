#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
struct node{
	int a,b,c,sub;
}p[N];
int tmp[3];
int ans;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		int ca,cb,cc;
		ca=cb=cc=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(max(p[i].a,max(p[i].b,p[i].c))==p[i].a){
				ca++;
				ans+=p[i].a;
				if(max(p[i].b,p[i].c)==p[i].b){
					p[i].sub=p[i].a-p[i].b;
				}
				else{
					p[i].sub=p[i].a-p[i].c;
				}
			}
			else if(max(p[i].a,max(p[i].b,p[i].c))==p[i].b){
				cb++;
				ans+=p[i].b;
				if(max(p[i].a,p[i].c)==p[i].a){
					p[i].sub=p[i].b-p[i].a;
				}
				else{
					p[i].sub=p[i].b-p[i].c;
				}
			}
			else{
				cc++;
				ans+=p[i].c;
				if(max(p[i].b,p[i].a)==p[i].a){
					p[i].sub=p[i].c-p[i].a;
				}
				else{
					p[i].sub=p[i].c-p[i].b;
				}
			}
		}
		if(ca>n/2){
			for(int i=1;i<=n;i++){
				if(max(p[i].a,max(p[i].b,p[i].c))!=p[i].a)continue;
				q.push(p[i].sub);
			}
			while(ca>n/2){
				ans-=q.top();q.pop();ca--;
			}
		}
		else if(cb>n/2){
			for(int i=1;i<=n;i++){
				if(max(p[i].a,max(p[i].b,p[i].c))!=p[i].b)continue;
				q.push(p[i].sub);
			}
			while(cb>n/2){
				ans-=q.top();q.pop();cb--;
			}	
		}
		else if(cc>n/2){
			for(int i=1;i<=n;i++){
				if(max(p[i].a,max(p[i].b,p[i].c))!=p[i].c)continue;
				q.push(p[i].sub);
			}
			while(cc>n/2){
				ans-=q.top();q.pop();cc--;
			}
		}
			
		cout<<ans<<'\n';
		while(!q.empty())q.pop();
		
	}
	return 0;
}