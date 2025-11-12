#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,cnt[4],v[N],n;
struct p{
	int a,b,c;
	int ma,mb,mc;
	int minn;
	int favour;
	int to;
}q[N];
bool cmp(p x, p y){
	return x.minn<y.minn;
}
queue<p>change;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=200){
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>q[i].a>>q[i].b>>q[i].c;
				q[i].favour=max(q[i].a,max(q[i].b,q[i].c));
				q[i].ma=q[i].favour-q[i].a;
				q[i].mb=q[i].favour-q[i].b;
				q[i].mc=q[i].favour-q[i].c;
				if(q[i].ma==0)cnt[1]++,v[i]=1;
				if(q[i].mb==0)cnt[2]++,v[i]=2;
				if(q[i].mc==0)cnt[3]++,v[i]=3;
				int x;//找移动花费最小 
				x=min(q[i].ma,min(q[i].mb,q[i].mc));
				if(x==q[i].ma&&v[i]!=1)q[i].to=1;
				else if(x==q[i].mb&&v[i]!=2)q[i].to=2;
				else if(x==q[i].mc&&v[i]!=3)q[i].to=3;
				q[i].minn=x;
				ans+=q[i].favour;
			}
			int limit=n/2;
			sort(q+1,q+1+n,cmp);
			for(int i=1;i<=3;i++){
				for(int j=1;j<=n;j++){
					if(v[j]==i&&cnt[i]>limit){
						change.push(p[j]);
						cnt[i]--;
					}
					if(cnt[i]<=limit)break;
				}
				if(cnt[i]<=limit)break;
			}
			int i=1;
			while(!change.empty()){
				int to=change.front().to;
				if(cnt[i]<limit&&i==to){
					cnt[i]++;
					p x=change.front();
					if(to==1)ans-=x.ma;
					if(to==2)ans-=x.mb;
					if(to==3)ans-=x.mc;
					change.pop();
				}
				else if(cnt[to]==limit){
					for(int j=1;j<=3;j++){
						if(cnt[i]<limit){
							cnt[i]++;
							p x=change.front();
							if(to==1)ans-=x.ma;
							if(to==2)ans-=x.mb;
							if(to==3)ans-=x.mc;
							change.pop();
						}
					}
				}
				else {
					i++;
					if(i!=3)i%=3;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}

