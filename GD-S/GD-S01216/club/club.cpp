#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,t,ans,flag[4];
struct p{
	int x1,y1,x2,y2;
	bool operator < (const p &w) const{return x1-x2<w.x1-w.x2;};
};
struct date{
	int x,y;
	bool operator < (const date &w) const{return x<w.x;};
};
priority_queue<date> D;
priority_queue<p> R;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		flag[1]=0,flag[2]=0,flag[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			D.push({x,1}),D.push({y,2}),D.push({z,3});
			int x1=D.top().x,y1=D.top().y;
			D.pop();
			int x2=D.top().x,y2=D.top().y;
			D.pop();D.pop();
			R.push({x1,y1,x2,y2});
		}
		while(!R.empty()){
			int x1=R.top().x1,x2=R.top().x2,
			y1=R.top().y1,y2=R.top().y2;
			R.pop();
			if(flag[y1]+1<=n/2){
				ans+=x1,flag[y1]++;
				continue;
			}
			ans+=x2,flag[y2]++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
 
