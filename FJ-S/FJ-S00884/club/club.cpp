#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(-x);return;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
struct node{
	int id,num;
}a[N][3];
bool cmp(node xi,node xj){
	return xi.num>xj.num;
}
int n,ans,T;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		for(int i=0;i<3;i++)while(!q[i].empty())q[i].pop();
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i][0].num=read();a[i][1].num=read();a[i][2].num=read();
			a[i][0].id=0,a[i][1].id=1;a[i][2].id=2;
			sort(a[i],a[i]+3,cmp); 
		} 
		for(int i=1;i<=n;i++){
			int id0=a[i][0].id,id1=a[i][1].id,num0=a[i][0].num,num1=a[i][1].num;
			if(q[id0].size()<n/2||num0-q[id0].top().first>=num1){
				if(q[a[i][0].id].size()<n/2)q[a[i][0].id].push(make_pair(a[i][0].num-a[i][1].num,i)),ans+=a[i][0].num;
				else{
					q[a[q[id0].top().second][1].id].push(make_pair(q[id0].top().first,q[id0].top().second));
					ans+=num0-q[id0].top().first;
					q[id0].pop();
					q[id0].push(make_pair(a[i][0].num-a[i][1].num,i));
				}
			}
			else{
				q[id1].push(make_pair(a[i][0].num-a[i][1].num,i));
				ans+=num1;
			}
		}
		print(ans);putchar('\n');
	}
	return 0;
}
/*
Rp++ Rp++ 
*/
