#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define N 100010
int T;
int n,m;
struct person{
	int a,b,c;
}a[N];
int to[N],b[N];
int s1,s2,s3;
priority_queue<int,vector<int>,greater<int>>q;
int ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		s1=s2=s3=0;
		ans=0;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++){
			a[i].a=read(),a[i].b=read(),a[i].c=read();
			int mx=max(a[i].a,max(a[i].b,a[i].c));
			ans+=mx;
			if(a[i].a==mx){
				to[i]=1;s1++;
				b[i]=mx-max(a[i].b,a[i].c);
			}
			else if(a[i].b==mx){
				to[i]=2;s2++;
				b[i]=mx-max(a[i].a,a[i].c);
			}
			else if(a[i].c==mx){
				to[i]=3;s3++;
				b[i]=mx-max(a[i].a,a[i].b);
			}
		}
//		cout<<ans<<" ";
		int up=0;
		if(s1>n/2)up=1;
		else if(s2>n/2)up=2;
		else if(s3>n/2)up=3;
		if(up){
			for(int i=1;i<=n;i++)
				if(to[i]==up){
					q.push(b[i]);
				}
//		cout<<q.size()<<" ";
			while(q.size()>n/2){
				ans-=q.top();
				q.pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

