#include<bits/stdc++.h>
using namespace std;
namespace estidi{
	const int mn=20003;
	struct num{
		int id,v,now;
		pair<int,int>ma,mma,mmma;
	};
	bool operator < (num a,num b){
		return a.v>b.v;
	}
	priority_queue<num>q[5];
	int read(){
		int x;
		char c;
		while(1){
			c=getchar();
			if('0'<=c&&c<='9')
				break;
		}
		x=c-'0';
		while(1){
			c=getchar();
			if('0'<=c&&c<='9')
				x=x*10+c-'0';
			else
				break;
		}
		return x;
	}
	int main(){
		int tc,n,ans,va,vb,vc;
		num x;
		tc=read();
		while(tc--){
			while(q[1].size())
				q[1].pop();
			while(q[2].size())
				q[2].pop();
			while(q[3].size())
				q[3].pop();
			n=read();
			ans=0;
			for(int i=1;i<=n;i++){
				va=read();
				vb=read();
				vc=read();
				x={i,0,1,{va,1},{vb,2},{vc,3}};
				if(x.ma<x.mma)
					swap(x.ma,x.mma);
				if(x.mma<x.mmma)
					swap(x.mma,x.mmma);
				if(x.ma<x.mma)
					swap(x.ma,x.mma);
				ans+=x.ma.first;
				x.v=x.ma.first-x.mma.first;
				q[x.ma.second].push(x);
			}
			while(q[1].size()>n/2||q[2].size()>n/2||q[3].size()>n/2){
				while(q[1].size()>n/2){
					x=q[1].top();
					q[1].pop();
					ans-=x.v;
					x.now++;
					assert(x.now<=3);
					if(x.now==2){
						x.v=x.mma.first-x.mmma.first;
						q[x.mma.second].push(x);
					}
					else{
						x.v=214748364;
						q[x.mmma.second].push(x);
					}
				}
				while(q[2].size()>n/2){
					x=q[2].top();
					q[2].pop();
					ans-=x.v;
					x.now++;
					assert(x.now<=3);
					if(x.now==2){
						x.v=x.mma.first-x.mmma.first;
						q[x.mma.second].push(x);
					}
					else{
						x.v=214748364;
						q[x.mmma.second].push(x);
					}
				}
				while(q[3].size()>n/2){
					x=q[3].top();
					q[3].pop();
					ans-=x.v;
					x.now++;
					assert(x.now<=3);
					if(x.now==2){
						x.v=x.mma.first-x.mmma.first;
						q[x.mma.second].push(x);
					}
					else{
						x.v=214748364;
						q[x.mmma.second].push(x);
					}
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	estidi::main();
	return 0;
}
//差点忘整活活活活活活活活活活活活活活活活活活活活活活活活活活活活活活活活活活活活活了 
//广告：Opoi 2025！ 
