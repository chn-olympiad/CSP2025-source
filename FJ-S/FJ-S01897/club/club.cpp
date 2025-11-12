#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,b[N];
struct node{
	int x,y,z,mx,p;
}a[N];
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void solve(){
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].x=read();
		a[i].y=read();
		a[i].z=read();
		a[i].mx=max(a[i].x,a[i].y);
		a[i].mx=max(a[i].mx,a[i].z);
		if(a[i].mx==a[i].x){
			a[i].p=0;
			b[i]=min(a[i].mx-a[i].y,a[i].mx-a[i].z);
		}else if(a[i].mx==a[i].y){
			a[i].p=1;
			b[i]=min(a[i].mx-a[i].x,a[i].mx-a[i].z);
		}else{
			a[i].p=2;
			b[i]=min(a[i].mx-a[i].y,a[i].mx-a[i].x);
		}
	}
	priority_queue<pair<int,int> > q[3];
	for(int i=1;i<=n;i++){
		q[a[i].p].push({-b[i],i});
		ans+=a[i].mx;
		if(q[a[i].p].size()>n/2){
			pair<int,int> x=q[a[i].p].top();
			int j=x.second;
			q[a[i].p].pop();
			ans-=b[j];
			if(a[j].p==0){
				if(a[j].y>a[j].z){
					b[j]=a[i].y-a[j].z;
					q[1].push({-b[j],j});
				}else{
					b[j]=a[i].z-a[j].y;
					q[2].push({-b[j],j});
				}
			}else if(a[j].p==1){
				if(a[j].x>a[j].z){
					b[j]=a[i].x-a[j].z;
					q[0].push({-b[j],j});
				}else{
					b[j]=a[i].z-a[j].x;
					q[2].push({-b[j],j});
				}
			}else{
				if(a[j].y>a[j].x){
					b[j]=a[i].y-a[j].x;
					q[1].push({-b[j],j});
				}else{
					b[j]=a[i].x-a[j].y;
					q[0].push({-b[j],j});
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve(); 
	return 0;
}

