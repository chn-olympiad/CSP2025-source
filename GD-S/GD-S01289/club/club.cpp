#include<bits/stdc++.h>
#define ll long long
#define int ll
#define oF(l,r,i) for(int i=l;i<=r;i++)
#define of(l,r) for(int i=l;i<=r;i++)
#define tF(n,i) oF(1,n,i)
#define tf(n) oF(1,n,i)
#define nF(i) oF(1,n,i)
#define nf() oF(1,n,i)
#define pb emplace_back
#define pint pair<int,int>
#define mp make_pair
#define f first
#define s second
#define file(x) (freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),0)
using namespace std;
ll read(){
	ll x=0;
	char c=getchar();
	while(c<48)c=getchar();
	while(c>47)x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x;
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
int xxx=file(club);
int T=read(),n,ans;
int a[100005][4];
struct dpq{
	priority_queue<pint>ele,del;
	int size(){
		return ele.size()-del.size();
	}
	pint top(){
		while(del.size()&&ele.top()==del.top())ele.pop(),del.pop();
		return ele.size()?ele.top():mp(-1145141919810ll,0ll);
	}
	void push(pint x){
		ele.push(x);
	}
	void erase(pint x){
		del.push(x);
	}
	void clear(){
		while(ele.size())ele.pop();
		while(del.size())del.pop();
	}
}p12,p13,p21,p23,p31,p32;
#define push1(x) p12.push(mp(a[x][2]-a[x][1],x)),p13.push(mp(a[x][3]-a[x][1],x))
#define push2(x) p21.push(mp(a[x][1]-a[x][2],x)),p23.push(mp(a[x][3]-a[x][2],x))
#define push3(x) p31.push(mp(a[x][1]-a[x][3],x)),p32.push(mp(a[x][2]-a[x][3],x))
#define del1(x) p12.erase(mp(a[x][2]-a[x][1],x)),p13.erase(mp(a[x][3]-a[x][1],x))
#define del2(x) p21.erase(mp(a[x][1]-a[x][2],x)),p23.erase(mp(a[x][3]-a[x][2],x))
#define del3(x) p31.erase(mp(a[x][1]-a[x][3],x)),p32.erase(mp(a[x][2]-a[x][3],x))
int insert(int pos,int x){
	if(pos==1){
		push1(x);
		if(p12.size()>n>>1){
			if(p12.top()>p13.top()){
				int v=p12.top().f,p=p12.top().s;
				del1(p);
				push2(p);
				return a[x][1]+v;
			}
			else{
				int v=p13.top().f,p=p13.top().s;
				del1(p);
				push3(p);
				return a[x][1]+v;
			}
		}
		return a[x][1];
	}
	if(pos==2){
		push2(x);
		if(p21.size()>n>>1){
			if(p21.top()>p23.top()){
				int v=p21.top().f,p=p21.top().s;
				del2(p);
				push1(p);
				return a[x][2]+v;
			}
			else{
				int v=p23.top().f,p=p23.top().s;
				del2(p);
				push3(p);
				return a[x][2]+v;
			}
		}
		return a[x][2];
	}
	if(pos==3){
		push3(x);
		if(p31.size()>n>>1){
			if(p31.top()>p32.top()){
				int v=p31.top().f,p=p31.top().s;
				del3(p);
				push1(p);
				return a[x][3]+v;
			}
			else{
				int v=p32.top().f,p=p32.top().s;
				del3(p);
				push2(p);
				return a[x][3]+v;
			}
		}
		return a[x][3];
	}
}
signed main(){
	while(T--){
		p12.clear();
		p13.clear();
		p21.clear();
		p23.clear();
		p31.clear();
		p32.clear();
		n=read(),ans=0;
		nf()a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		nf(){
			ans+=insert(max({1,2,3},[i](int x,int y){return a[i][x]<a[i][y];}),i);
		}
		write(ans);putchar(10);
	}
}
