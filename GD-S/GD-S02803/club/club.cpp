#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
priority_queue<pair<ll,int> >a,b,c;
int t,n,s1,s2,s3;
ll v[N][4],ans;
void add(int x,int y){
	if(y==1){
		a.push({-v[x][1]+max(v[x][2],v[x][3]),x});
		s1++;
	}
	if(y==2){
		b.push({-v[x][2]+max(v[x][1],v[x][3]),x});
		s2++;
	}
	if(y==3){
		c.push({-v[x][3]+max(v[x][1],v[x][2]),x});
		s3++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		s1=s2=s3=0;
		while(!a.empty()){
//			cout<<a.top().second<<"\n";
			a.pop();
		}
		while(!b.empty()){
//			cout<<b.top().second<<"\n";
			b.pop();
		}
		while(!c.empty()){
//			cout<<c.top().second<<"\n";
			c.pop();
		}
		for(int i=1;i<=n;i++)
			cin>>v[i][1]>>v[i][2]>>v[i][3];
		for(int i=1;i<=n;i++){
			ll x,y,z;
			if(s1==n/2)
				x=v[i][1]+a.top().first;
			else
				x=v[i][1];
			if(s2==n/2)
				y=v[i][2]+b.top().first;
			else
				y=v[i][2];
			if(s3==n/2)
				z=v[i][3]+c.top().first;
			else
				z=v[i][3];
			ll mx=max(max(x,y),z);
			if(mx==x){
				if(s1==n/2){
					int k=a.top().second;
					a.pop();
					s1--;
					if(v[k][2]>v[k][3])
						add(k,2);
					else
						add(k,3);
				}
				add(i,1);
			}
			else if(mx==y){
				if(s2==n/2){
					int k=b.top().second;
					b.pop();
					s2--;
					if(v[k][1]>v[k][3])
						add(k,1);
					else
						add(k,3);
				}
				add(i,2);
			}
			else{
				if(s3==n/2){
					int k=c.top().second;
					c.pop();
					s3--;
					if(v[k][2]>v[k][1])
						add(k,2);
					else
						add(k,1);
				}
				add(i,3);
			}
			ans+=mx;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
