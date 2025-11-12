#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return f*a;
}
int t,n;
struct node{
	int x,y,z;
}a[N];
int s[5];
priority_queue<int>q;
int maxn(int x,int y,int z){
	return max(max(x,y),z);
}
void cl(){
	while(!q.empty())q.pop();
	s[1]=s[2]=s[3]=0;
	n=read();
	ll ans=0;
	for(int i=1;i<=n;i++)
		a[i].x=read(),a[i].y=read(),a[i].z=read(),ans+=maxn(a[i].x,a[i].y,a[i].z);
	for(int i=1;i<=n;i++){
		int k=maxn(a[i].x,a[i].y,a[i].z);
		if(k==a[i].x)s[1]++;
		else if(k==a[i].y)s[2]++;
		else if(k==a[i].z)s[3]++;
	}
	if(s[1]<=n/2&&s[2]<=n/2&&s[3]<=n/2){
		printf("%lld\n",ans);
		return;
	}
	if(s[1]>n/2){
		for(int i=1;i<=n;i++){
			int k=maxn(a[i].x,a[i].y,a[i].z);
			if(k==a[i].x)q.push(max(a[i].y,a[i].z)-a[i].x);
		}
		int cnt=s[1]-n/2;
		while(cnt--)
			ans+=q.top(),q.pop();
		printf("%lld\n",ans);
		return;
	}
	if(s[2]>n/2){
		for(int i=1;i<=n;i++){
			int k=maxn(a[i].x,a[i].y,a[i].z);
			if(k!=a[i].x&&k==a[i].y)q.push(max(a[i].x,a[i].z)-a[i].y);
		}
		int cnt=s[2]-n/2;
		while(cnt--)
			ans+=q.top(),q.pop();
		printf("%lld\n",ans);
		return;
	}
	if(s[3]>n/2){
		for(int i=1;i<=n;i++){
			int k=maxn(a[i].x,a[i].y,a[i].z);
			if(k!=a[i].x&&k!=a[i].y)q.push(max(a[i].x,a[i].y)-a[i].z);
		}
		int cnt=s[3]-n/2;
		while(cnt--)
			ans+=q.top(),q.pop();
		printf("%lld\n",ans);
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
		cl();
	return 0;
}
//14:50
