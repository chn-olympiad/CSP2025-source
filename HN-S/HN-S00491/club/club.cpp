#include <bits/stdc++.h>
using namespace std;
const int INF=1e5;
struct S{
	int a1;
	int a2;
	int a3;
};
bool cmp1(S x,S y){
	return x.a1>y.a1;
}
bool cmp2(S x,S y){
	return x.a2>y.a2;
}
bool cmp3(S x,S y){
	return x.a3>y.a3;
}
void pr(){
	int n,h[4]={0,0,0,0};
	int ans=0,ansn=0;
	scanf("%d",&n);
	S x[n+5];
	priority_queue<int,vector<int>,greater<int> > q;
	int ab;
	//
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&x[i].a1,&x[i].a2,&x[i].a3);
		ab=max(x[i].a1,max(x[i].a2,x[i].a3));
		if(x[i].a1==x[i].a2&&x[i].a1==x[i].a3){
			h[1]++,h[2]++,h[3]++;
			continue;
		}
		if(x[i].a1==x[i].a2){
			h[1]++,h[2]++;
			continue;
		}
		if(x[i].a3==x[i].a2){
			h[3]++,h[2]++;
			continue;
		}
		if(x[i].a1==x[i].a3){
			h[1]++,h[3]++;
			continue;
		}
		if(ab==x[i].a1) h[1]++;
		if(ab==x[i].a2) h[2]++;
		if(ab==x[i].a3) h[3]++;
	}
	if(h[1]>n/2){
		if(h[2]>=h[3])
		sort(x+1,x+n+1,cmp2);
		else sort(x+1,x+n+1,cmp3);
		for(int i=1;i<=n/2;i++){
			ans+=x[i].a1;
			q.push(min(x[i].a1-x[i].a2,x[i].a1-x[i].a3));
		}
		for(int i=n/2+1;i<=n;i++){
			if(x[i].a1>=q.top()){
				ans-=q.top();
				q.pop();
				q.push(min(x[i].a1-x[i].a2,x[i].a1-x[i].a3));
				ans+=x[i].a1;
			}
		}
		//cout<<"t1";
	}else
	if(h[2]>n/2){
		if(h[1]>=h[3])
		sort(x+1,x+n+1,cmp1);
		else sort(x+1,x+n+1,cmp3);
		for(int i=1;i<=n/2;i++){
			ans+=x[i].a2;
			q.push(min(x[i].a2-x[i].a1,x[i].a2-x[i].a3));
		}
		for(int i=n/2+1;i<=n;i++){
			if(x[i].a2>q.top()){
				ans-=q.top();
				q.pop();
				q.push(min(x[i].a2-x[i].a1,x[i].a2-x[i].a3));
				ans+=x[i].a2;
			}
		}
		//cout<<"t2";
	}else
	if(h[3]>n/2){
		if(h[2]>=h[1])
		sort(x+1,x+n+1,cmp2);
		else sort(x+1,x+n+1,cmp1);
		for(int i=1;i<=n/2;i++){
			ans+=x[i].a3;
			q.push(min(x[i].a3-x[i].a2,x[i].a3-x[i].a1));
		}
		for(int i=n/2+1;i<=n;i++){
			if(x[i].a3>q.top()){
				ans-=q.top();
				q.pop();
				q.push(min(x[i].a3-x[i].a2,x[i].a3-x[i].a1));
				ans+=x[i].a3;
			}
		}
	}else{
		for(int i=1;i<=n;i++) ans+=max(x[i].a1,max(x[i].a2,x[i].a3));
	}
	printf("%d\n",ans);
	return;
}
int main ()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		pr();
	}
	return 0;
}
