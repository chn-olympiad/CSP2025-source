#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,T,a[N],b[N],c[N],d[4],cnt,sum;
long long ans;
struct node{
	int id,d,val;
	bool operator < (const node &x) const{
		return val>x.val;
	}
};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		priority_queue<node> q,q1,q2;
		ans=0,cnt=0,sum=0;
		for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]==0&&c[i]==0) cnt++;
			if(a[i]>=b[i]&&a[i]>=c[i]){
				q.push({i,1,a[i]});
				d[1]++;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				q1.push({i,2,b[i]});
				d[2]++;
			}else q2.push({i,3,c[i]}),d[3]++;
		}
		if(n==2){
		int x1=0,x2=0,x3=0;
		x1=a[1]+max(b[2],c[2]);
		x2=b[1]+max(a[2],c[2]);
		x3=c[1]+max(a[2],b[2]);
		ans=max(x1,max(x2,x3));
		cout<<ans<<'\n';
		continue;
		}
		if(cnt==n){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i];
			cout<<ans<<'\n';
			continue;
		}
		while(q.size()>n/2){
			node x=q.top();
			q.pop();
			if(b[x.id]>c[x.id]){
				q1.push({x.id,2,b[x.id]});
			}else if(b[x.id]==c[x.id]){
				if(q1.size()<q2.size()){
					q1.push({x.id,2,b[x.id]});
				}else q2.push({x.id,3,c[x.id]});
			}else{
				q2.push({x.id,3,c[x.id]});
			}
		}
		while(q1.size()>n/2){
			node x=q1.top();
			q1.pop();
			if(a[x.id]<c[x.id])
			q2.push({x.id,3,c[x.id]});
			else if(a[x.id]==c[x.id]){
				if(q.size()<q2.size()){
					q2.push({x.id,1,a[x.id]});
				}else q2.push({x.id,3,c[x.id]});
			}else q2.push({x.id,1,a[x.id]});
		}
		while(q2.size()>n/2){
			node x=q2.top();
			q2.pop();
			if(a[x.id]>b[x.id]){
				q.push({x.id,1,a[x.id]});
			}else if(a[x.id]==b[x.id]){
				if(q.size()<q1.size()){
					q.push({x.id,1,a[x.id]});
				}else q1.push({x.id,2,b[x.id]});
			}else q1.push({x.id,2,b[x.id]});
		}
		while(!q.empty()){
			node x=q.top();
			q.pop();
			ans+=x.val;
		}
		while(!q1.empty()){
			node x=q1.top();
			q1.pop();
			ans+=x.val;
		}
		while(!q2.empty()){
			node x=q2.top();
			q2.pop();
			ans+=x.val;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
