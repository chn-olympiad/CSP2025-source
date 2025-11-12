#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,f1,f2,x; 
} ;
bool operator < (const node a,const node b){
	return a.x>b.x;
}
node d[100005];
priority_queue<node> q;
struct node1{
	int i,data;
};
priority_queue<node> q1,q2,q3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,j,m;
	long long ans;
	node tmp;
	cin>>t;
	while(t--){
		ans=0;
		scanf("%d",&n);
		m=n/2;
		while(!q.empty()){
			q.pop();
		}
		while(!q1.empty()){
			q1.pop();
		}
		while(!q2.empty()){
			q2.pop();
		}
		while(!q3.empty()){
			q3.pop();
		}
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
			d[i].f1=max(d[i].a,max(d[i].b,d[i].c));
			if(d[i].a>=d[i].b&&d[i].b>=d[i].c) d[i].f2=d[i].b;
			else if(d[i].a>=d[i].c&&d[i].c>=d[i].b) d[i].f2=d[i].c;
			else d[i].f2=d[i].a;
			d[i].x=d[i].f1-d[i].f2;
			q.push(d[i]);
		}
		for(i=0;i<n;i++)
		{
			tmp=q.top();
//			d[i]=tmp;
			q.pop();
			if(tmp.f1==tmp.a){
				if(q1.size()<m){
					ans+=tmp.f1;
					q1.push(tmp);
				}
				else{
					node tmp1=q1.top();
					if(tmp.f1-tmp1.x>=tmp.f2){
						q1.pop();
						q1.push(tmp);
						ans+=tmp.f1;ans-=tmp1.x;
					}else{
						ans+=tmp.f2;
					}
				}
			}
			else if(tmp.f1==tmp.b){
				if(q2.size()<m){
					ans+=tmp.f1;
					q2.push(tmp);
				}
				else{
					node tmp1=q2.top();
					if(tmp.f1-tmp1.x>=tmp.f2){
						q2.pop();
						q2.push(tmp);
						ans+=tmp.f1;ans-=tmp1.x;
					}else{
						ans+=tmp.f2;
					}
				}
			}
			else if(tmp.f1==tmp.c){
				if(q3.size()<m){
					ans+=tmp.f1;
					q3.push(tmp);
				}
				else{
					node tmp1=q3.top();
					if(tmp.f1-tmp1.x>=tmp.f2){
						q3.pop();
						q3.push(tmp);
						ans+=tmp.f1;ans-=tmp1.x;
					}else{
						ans+=tmp.f2;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
