#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z;
struct node{
	int a,b,c,cha;
	bool operator<(const node&d)const{
		if(cha!=d.cha){
			return cha<d.cha;
		}else{
			return int(max(a,max(b,c)))>int(max(d.a,max(d.b,d.c)));
		}
	}
};
int a,b,c,ans;
priority_queue<node>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
	while(t--){
		cin>>n;
		a=b=c=ans=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			q.push({x,y,z,max({x,y,z})-min({x,y,z})});
		}
		while(!q.empty()){
			node h=q.top();
			q.pop();
			int v[4]={h.a,h.b,h.c,max({h.a,h.b,h.c})};
			if(v[0]==v[3]){
				if(a<n/2){
					a++,ans+=v[0];
				}else if(v[1]>=v[2]){
					if(b<n/2){
						b++,ans+=v[1];
					}else{
						c++,ans+=v[2];
					}
				}else{
					if(c<n/2){
						c++,ans+=v[2];
					}else{
						b++,ans+=v[1];
					}
				}
			}else if(v[1]==v[3]){
				if(b<n/2){
					b++,ans+=v[1];
				}else if(v[0]>=v[2]){
					if(a<n/2){
						a++,ans+=v[0];
					}else{
						c++,ans+=v[2];
					}
				}else{
					if(c<n/2){
						c++,ans+=v[2];
					}else{
						a++,ans+=v[0];
					}
				}
			}else{
				if(c<n/2){
					c++;
					ans+=v[2];
				}else if(v[0]>=v[1]){
					if(a<n/2){
						a++,ans+=v[0];
					}else{
						b++,ans+=v[1];
					}
				}else{
					if(b<n/2){
						b++,ans+=v[1];
					}else{
						a++,ans+=v[0];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
/*
CSP-S T1 Club
*/
