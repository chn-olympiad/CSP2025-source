#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Q{
	int x,id;
	bool operator<(Q b)const {
		bool flag=x>b.x;
		return flag;
	}
} s;
priority_queue<Q> q[2];
struct T{
	int a,b,c;
} a[N];
int t,n,ans,max1,max2;
void dfs(int x,int s1,int s2,int s3,int sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(s1) dfs(x+1,s1-1,s2,s3,sum+a[x].a);
	if(s2) dfs(x+1,s1,s2-1,s3,sum+a[x].b);
	if(s3) dfs(x+1,s1,s2,s3-1,sum+a[x].c);
}
bool cmp(T x,T y){
	if(x.a==y.a) return x.b>y.b;
	return x.a>y.a;
}
void clear(){
	while(!q[0].empty()) ans+=q[0].top().x,q[0].pop();
	while(!q[1].empty()) ans+=q[1].top().x,q[1].pop();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		const int M=n/2;
		for(int i=1;i<=n;++i){
			cin>>a[i].a>>a[i].b>>a[i].c;
			max1=max(max1,a[i].b);
			max2=max(max2,a[i].c);
		}
		if(max1==max2&&max1==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=M;++i) ans+=a[i].a;
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		if(max2==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;++i){
				int x=a[i].a,y=a[i].b;
				if(q[0].size()==M) x-=q[0].top().x+a[q[0].top().id].b;
				else if(q[1].size()==M) y-=q[1].top().x;
				if(x>y){
					if(q[0].size()==M){
						s.x=a[q[0].top().id].b;
						s.id=q[0].top().id;
						q[1].push(s);
						q[0].pop();
					}
					s.x=a[i].a;
					s.id=i;
					q[0].push(s);
				}
				else{
					if(q[1].size()==M){
						s.x=a[q[1].top().id].b;
						s.id=q[1].top().id;
						q[0].push(s);
						q[1].pop();
					}
					s.x=a[i].b;
					s.id=i;
					q[1].push(s);
				}
			}
			clear();
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		dfs(1,M,M,M,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
