#include<bits/stdc++.h>
using namespace std;
struct st{
	int a,b,c;
}a[100010],e;
struct St{
	int v,w,ta,tb,tc;
}p;
int T,n;
long long ans,b[100010];
void dfs(int u,long long w,int ta,int tb,int tc){
	if(u==n+1){
		ans=max(ans,w);
		return;
	}
	if(ta<n/2)dfs(u+1,w+a[u].a,ta+1,tb,tc);
	if(tb<n/2)dfs(u+1,w+a[u].b,ta,tb+1,tc);
	if(tc<n/2)dfs(u+1,w+a[u].c,ta,tb,tc+1);
}
bool cmp1(st x,st y){
	return x.a>y.a;
}
bool cmp2(int x,int y){
	int c1=a[x].a-a[x].b,c2=a[y].a-a[y].b;
	return c1<c2;
}
bool cmp3(int x,int y){
	int c1=a[x].a-a[x].b,c2=a[y].a-a[y].b;
	return c1>c2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n;
		int f1=1,f2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0)f2=f1=0;
			if(a[i].b!=0)f1=0;
		}
		if(f1){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)ans+=a[i].a;
			cout<<ans<<endl;
		}
		else if(f2){
			vector<int> A,B;
			for(int i=1;i<=n;i++){
				if(a[i].a>a[i].b)A.push_back(i);
				else B.push_back(i);
			}
			int la=A.size(),lb=B.size();
			if(la>lb){
				sort(A.begin(),A.end(),cmp3);
				for(int i=0;i<n/2;i++)ans+=a[A[i]].a;
				for(int i=n/2;i<la;i++)ans+=a[A[i]].b;
				for(int i=0;i<lb;i++)ans+=a[B[i]].b;
			}
			else if(B.size()>A.size()){
				sort(B.begin(),B.end(),cmp2);
				for(int i=0;i<n/2;i++)ans+=a[B[i]].b;
				for(int i=n/2;i<lb;i++)ans+=a[B[i]].a;
				for(int i=0;i<la;i++)ans+=a[A[i]].a;
			}
			else{
				for(int i=0;i<la;i++)ans+=a[A[i]].a;
				for(int i=0;i<lb;i++)ans+=a[A[i]].b;
			}
			cout<<ans<<endl;
		}
		else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
