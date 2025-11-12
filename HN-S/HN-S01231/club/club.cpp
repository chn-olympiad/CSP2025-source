#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int cnt=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=!f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return ((f==0)?cnt:-cnt);
}

void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar((char)(x%10+'0'));
}

int n,t;

struct node{
	int x[5],id[5],zong;
}a[100005];

int tong[5],ans,cnt,b[100005];

bool cmp2(int a,int b){
	return a>b;
}

int dp[100005];

void dfs(int setp){
	if(setp>n){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(tong[a[setp].id[i]]<n/2){
			cnt+=a[setp].x[i];
			tong[a[setp].id[i]]++;
			dfs(setp+1);
			tong[a[setp].id[i]]--;
			cnt-=a[setp].x[i];
		}
	}
}

struct node2{
	int x,id,zong;
	bool operator < (const node2 &b) const{
		if(x==b.x)return b.zong<zong;
		return x<b.x;
	}
};

priority_queue<node2> q1,q2,q3;

bool cmp(node a,node b){
	return a.zong<b.zong;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,cnt=0;
		memset(tong,0,sizeof tong);
		bool f=0,flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			a[i].id[1]=1,a[i].id[2]=2,a[i].id[3]=3;
			a[i].zong=a[i].x[1]+a[i].x[2]+a[i].x[3];
			if(a[i].x[3]>a[i].x[1]){
				swap(a[i].x[1],a[i].x[3]);
				swap(a[i].id[1],a[i].id[3]);
			}
			if(a[i].x[1]<a[i].x[2]){
				swap(a[i].x[2],a[i].x[1]);
				swap(a[i].id[1],a[i].id[2]);
			}
			if(a[i].x[3]>a[i].x[2]){
				swap(a[i].x[2],a[i].x[3]);
				swap(a[i].id[3],a[i].id[2]);
			}
			if(a[i].x[2]>0||a[i].x[3]>0){
				f=1;
			}
			if(a[i].x[3]>0){
				flag=1;
			}
		}
		if(f==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i].x[1];
			}
			sort(b+1,b+1+n,cmp2);
			for(int i=1;i<=n;i++){ 
			 if(i<=n/2)ans+=b[i];
				else break;
			}
			cout<<ans<<'\n';
		}else if(n<=10){
			dfs(1);
			cout<<ans<<'\n';
		}else{
			sort(a+1,a+1+n,cmp);
			bool f=0;
			for(int i=1;i<=n;i++){
				q1.push(node2{a[i].x[1],i,a[i].zong});
				while(q1.size()>n/2){
					node2 t=q1.top();
					q1.pop();
					if(t.id==i)f=1;
					for(int j=2;j<=3;j++){
						q2.push(node2{a[t.id].x[j],t.id,a[t.id].zong});
					}
				}
				if(f==1){
					f=0;
					q2.push(node2{a[i].x[2],i,a[i].zong});
					while(q2.size()>n/2){
						node2 t=q2.top();
						q2.pop();
						if(t.id==i)f=1;
						for(int j=3;j<=3;j++){
							q3.push(node2{a[t.id].x[j],t.id,a[t.id].zong});
						}
					}
				}
				if(f==1){
					q3.push(node2{a[i].x[3],i,a[1].zong});
					while(q3.size()>n/2){
						q3.pop();
					} 
				}
			}
			while(!q1.empty())ans+=q1.top().x,q1.pop();
			while(!q2.empty())ans+=q2.top().x,q2.pop();
			while(!q3.empty())ans+=q3.top().x,q3.pop();
			cout<<ans<<'\n';
		}
	}
	return 0;
}

