#include<bits/stdc++.h>
using namespace std;
struct we{
	int a,b,c;
}p[1000005],w[1000005],e[1000005];
priority_queue<int>q;
int n;
long long ans=0;
int ans1,ans2,ans3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0,ans1=0,ans2=0,ans3=0;
		while(q.size())q.pop();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 p[i]=w[i]=e[i]=we({0,0,0});
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a>=b&&a>=c)p[++ans1]=we({a,b,c}),ans+=a;
		else if(b>=a&&b>=c)w[++ans2]=we({a,b,c}),ans+=b;
		else if(c>=a&&c>=b)e[++ans3]=we({a,b,c}),ans+=c;
	}
	if(ans1>n/2){
		for(int i=1;i<=ans1;i++)
		 q.push(max(p[i].b-p[i].a,p[i].c-p[i].a));
		 while(q.size()>n/2){
		 	ans+=q.top();
		 	q.pop();
		 }
	}
	else if(ans2>n/2){
		for(int i=1;i<=ans2;i++)
		 q.push(max(w[i].a-w[i].b,w[i].c-w[i].b));
		 while(q.size()>n/2){
		 	ans+=q.top();
		 	q.pop();
		 }
	}
	else if(ans3>n/2){
		for(int i=1;i<=ans3;i++)
		 q.push(max(e[i].b-e[i].c,e[i].a-e[i].c));
		 while(q.size()>n/2){
		 	ans+=q.top();
		 	q.pop();
		 }
	}
	printf("%lld\n",ans);
	}
	
	return 0;
}
