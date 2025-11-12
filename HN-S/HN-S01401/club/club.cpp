#include<bits/stdc++.h>
using namespace std;
struct sdt{
	int num,id;
	operator<(const sdt &t)const{
		return num<t.num;
	}
};
bool cmp(int a,int b,int c,int d){
	if(a!=b)return a>b;
	else return c<=d;
}
int a1[100006],b1[100006],c1[100006],n;
int ans=-100;
void dfs(int now,int x,int y,int z,int cnt){
	if(n/2<x||n/2<y||n/2<z||now>n)return;
	ans=max(ans,cnt);
	dfs(now+1,x+1,y,z,cnt+a1[now+1]);
	dfs(now+1,x,y+1,z,cnt+b1[now+1]);
	dfs(now+1,x,y,z+1,cnt+c1[now+1]);
//	cout<<now<<' '<<cnt<<'\n';
}
priority_queue<sdt> a,b,c,d,e,f,g;
int a_[1000006],b_[1000006],c_[1000006];
bool bl[100005];
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(bl,0,sizeof(bl));
//		cout<<1;
		a=d;
		b=d;
		c=d;
		int ans=0;
		scanf("%d",&n);
		if(n<17){
			ans=-100;
			memset(a1,0,sizeof(a1));
			memset(b1,0,sizeof(b1));
			memset(c1,0,sizeof(c1));
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>a1[i]>>b1[i]>>c1[i];
			}
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			
			int a1,b1,c1;
			scanf("%d%d%d",&a1,&b1,&c1);//cout<<1;
			a.push((sdt){a1,i});
			b.push((sdt){b1,i});
			c.push((sdt){c1,i});
		}
		int alen=0,blen=0,clen=0;
		while(!a.empty()&&!b.empty()&&!c.empty()){
			while(bl[a.top().id]&&!a.empty()){
				a.pop();
			}
			while(bl[b.top().id]&&!b.empty()){
				b.pop();
			}
			while(bl[c.top().id]&&!b.empty()){
				c.pop();
			}
			
			if(a.empty()||a.empty()||a.empty())break;
//			cout<<a.size()<<' '<<b.size()<<' '<<c.size()<<'\n';
			int x=a.top().num,y=b.top().num,z=c.top().num;
			if(e.size()>=(n/2))x=-1;
			if(f.size()>=(n/2))y=-1;
			if(g.size()>=(n/2))z=-1;
			if(x==max(x,max(y,z))){
//				cout<<"1111";
				ans+=x;
				alen++;
				bl[a.top().id]=1;
				a.pop();
			}
			else if(y==max(x,max(y,z))){
//				cout<<"2222";
				ans+=y;
				blen++;
				bl[b.top().id]=1;
				b.pop();
			}
			else if(z==max(x,max(y,z))){
//				cout<<"33333";
				ans+=z;
				clen++;
//				cout<<3;
				bl[c.top().id]=1;
				c.pop();
			}
//			cout<<1;
		}cout<<ans<<'\n';
	}
}
