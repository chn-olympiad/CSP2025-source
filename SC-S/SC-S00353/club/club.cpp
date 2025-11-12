#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) x&-x
const int N=1e5+5;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
int T,n,nw=0;
struct node{
	int p1,p2,p3;//mis1=p1-p2,mis2=p1-p3
}a[N];
struct nd{
	int c1,c2,id;
	friend bool operator<(nd x,nd y){
		return max(x.c1,x.c2)<max(y.c1,y.c2);
	}
};
priority_queue<nd> q1,q2,q3;
ll ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			nd sdd,ot,ano;;
			sdd.id=i;
			ans=0;
			a[i].p1=read(),a[i].p2=read(),a[i].p3=read();
			if(max(a[i].p1,a[i].p2)<=a[i].p3){
				sdd.c1=a[i].p1-a[i].p3,sdd.c2=a[i].p2-a[i].p3;
				q3.push(sdd);
				if(q3.size()>n/2){
					ot=q3.top();
					q3.pop();
					if(ot.c1>=ot.c2){
						ano.c1=a[ot.id].p2-a[ot.id].p1,ano.c2=a[ot.id].p3-a[ot.id].p1;
						ano.id=ot.id;
						q1.push(ano);
					}
					else{
						ano.c1=a[ot.id].p1-a[ot.id].p2,ano.c2=a[ot.id].p3-a[ot.id].p2;
						ano.id=ot.id;
						q2.push(ano);
					}
				} 
			}
			else if(a[i].p1<=a[i].p2){
				sdd.c1=a[i].p1-a[i].p2,sdd.c2=a[i].p3-a[i].p2;
				q2.push(sdd);
				if(q2.size()>n/2){
					ot=q2.top();
					q2.pop();
					if(ot.c1>=ot.c2){
						ano.c1=a[ot.id].p2-a[ot.id].p1,ano.c2=a[ot.id].p3-a[ot.id].p1;
						ano.id=ot.id;
						q1.push(ano);
					}
					else{
						ano.c1=a[ot.id].p1-a[ot.id].p3,ano.c2=a[ot.id].p2-a[ot.id].p3;
						ano.id=ot.id;
						q3.push(ano);
					}
				} 
			}
			else{
				sdd.c1=a[i].p2-a[i].p1,sdd.c2=a[i].p3-a[i].p1;
				q1.push(sdd);
				if(q1.size()>n/2){
					ot=q1.top();
					q1.pop();
					if(ot.c1>=ot.c2){
						ano.c1=a[ot.id].p1-a[ot.id].p2,ano.c2=a[ot.id].p3-a[ot.id].p2;
						ano.id=ot.id;
						q2.push(ano);
					}
					else{
						ano.c1=a[ot.id].p1-a[ot.id].p3,ano.c2=a[ot.id].p2-a[ot.id].p3;
						ano.id=ot.id;
						q3.push(ano);
					}
				} 
			}
		}
		while(!q1.empty()){
			nd sd=q1.top();
			q1.pop();
//			cout<<1<<" "<<sd.id<<endl;
			ans+=a[sd.id].p1;
		}
		while(!q2.empty()){
			nd sd=q2.top();
			q2.pop();
//			cout<<2<<" "<<sd.id<<endl;
			ans+=a[sd.id].p2;
		}
		while(!q3.empty()){
			nd sd=q3.top();
			q3.pop();
//			cout<<3<<" "<<sd.id<<endl;
			ans+=a[sd.id].p3;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/