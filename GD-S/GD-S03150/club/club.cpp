#include<bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
const int N = 1e5+3;
inline int re(){
	int x=0;bool f=0;char c=gc();
	for(;c<'0'||c>'9';c=gc())f=c=='-';
	for(;c>='0'&&c<='9';c=gc())x=x*10-48+c;
	return f?-x:x;
}
inline int scmax(int x,int y,int z){//次大 
	if(x<y)swap(x,y);
	if(x<z)swap(x,z);
	if(y<z)swap(y,z);
	return y;
}
void sol(){
	int n=re();
	ll ans=0;
	priority_queue<ll> q1,q2,q3;
	for(int i=1,x,y,z,mx,smx;i<=n;i++){
		x=re(),y=re(),z=re();
		mx=max(max(x,y),z);
		ans+=mx,smx=scmax(x,y,z);
		if(x==mx)q1.push(smx-mx);
		else if(y==mx)q2.push(smx-mx);
		else q3.push(smx-mx);
	}
	if(q1.size()>(n/2)){
		while(q1.size()>n/2){
			ans+=q1.top();
			q1.pop();
		}
	}
	else if(q2.size()>(n/2)){
		while(q2.size()>n/2){
			ans+=q2.top();
			q2.pop();
		}
	}
	else if(q3.size()>(n/2)){
		while(q3.size()>n/2){
			ans+=q3.top();
			q3.pop();
		}
	}
	cout<<ans<<'\n';
}
/*
先把所有人扔进他们最满意的堆里
最多只有一个堆是爆满的
那么考虑对里面的人调剂到没满的组里
那么肯定是要减少的满足感最小 
发现只要按满足感最大和次大的差排序后依次扔出去即可 
因为无论怎么调剂，剩下两个堆一定不会超 
*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = re();
	while(T--)sol();
	return 0; 
}
