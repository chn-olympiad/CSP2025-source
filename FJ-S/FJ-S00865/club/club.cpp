#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll read(){
	ll ans=0,w=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-'){
			w=-w;
		}
		s=getchar();
	}
	while(isdigit(s)){
		ans=(ans<<3LL)+(ans<<1LL)+(s^48);
		s=getchar();
	}
	return ans*w;
}

const int N=1e5+10;
ll d[N][3];
ll op[N],f[N][3];
ll vis[N];
ll n;
priority_queue<ll> q;

void init(){
	for(int i=0;i<=3;i++){
		vis[i]=0;
	}
	while(!q.empty()){
		q.pop();
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t=read();
	while(t--){
		init(); 
		n=read();
		for(int i=1;i<=n;i++){
			d[i][0]=f[i][0]=read();
			d[i][1]=f[i][1]=read();
			d[i][2]=f[i][2]=read();
		}
		
		for(int i=1;i<=n;i++){
			sort(f[i],f[i]+3);
		} 
		
		ll cur=0;
		for(int i=1;i<=n;i++){
			ll mx=max({d[i][0],d[i][1],d[i][2]});
			cur+=mx;
			if(d[i][0]==mx){
				vis[0]++;
				op[i]=0;
			}
			else if(d[i][1]==mx){
				vis[1]++;
				op[i]=1;
			}
			else{
				vis[2]++;
				op[i]=2;
			}
		}
		
		if(max({vis[0],vis[1],vis[2]})>n/2){
			ll id=-1;
			for(int i=0;i<3;i++){
				if(vis[i]>n/2){
					id=i;
				}
			}
			
			for(int i=1;i<=n;i++){
				if(op[i]==id){
					q.push(f[i][1]-f[i][2]);
				}
			}
			
			while(vis[id]>n/2){
				cur+=q.top();
				q.pop();
				vis[id]--;
			}
			printf("%lld\n",cur);
		}
		else{
			printf("%lld\n",cur);
		}
	}
	
	return 0;
}
