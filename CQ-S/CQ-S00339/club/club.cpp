#include<bits/stdc++.h>
#define ll int
using namespace std;
const ll N=1e5+5,mod=1e9+7;
struct ACB{
	ll x,y;
	bool operator<(const ACB&z)const{
		return z.x<x;
	}
}o;
ll t,n,m,x,y,z,a[N][5],f[N][3],b[N][3],sum;
priority_queue<ACB>q[4];
struct FastIO{
	char buf[1<<21];
	ll len,pro;
	char getc(){
		if(len==pro)len=fread(buf,1,sizeof(buf),stdin),pro=0;
		return pro<len?buf[pro++]:EOF;
	}
	ll read_ll(){
		ll x=0,y=1;char c=getc();
		while(c<'0'||c>'9'){if(c=='-')y=-1;c=getc();}
		while('0'<=c&&c<='9')x=x*10+(c-'0'),c=getc();
		return x*y;
	}
	void write_ll(ll x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write_ll(x/10);
		putchar(x%10+'0');
	}
	
}io;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=io.read_ll();
	while(t--){
		n=io.read_ll();
		m=n/2;
		sum=0;
		for(ll i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
		for(ll i=1;i<=n;i++){
			a[i][1]=io.read_ll();
			a[i][2]=io.read_ll();
			a[i][3]=io.read_ll();
			x=a[i][1];
			y=a[i][2];
			z=a[i][3];
			if(x>y){
				if(x>z){
					f[i][1]=x;
					b[i][1]=1;
					if(y>z){
						f[i][2]=y;
						b[i][2]=2;
					}
					else{
						f[i][2]=z;
						b[i][2]=3;
					}
				}
				else{
					f[i][1]=z;
					b[i][1]=3;
					f[i][2]=x;
					b[i][2]=1;
				}
			}
			else{
				if(y>z){
					f[i][1]=y;
					b[i][1]=2;
					if(x>z){
						f[i][2]=x;
						b[i][2]=1;
					}
					else{
						f[i][2]=z;
						b[i][2]=3;
					}
				}
				else{
					f[i][1]=z;
					b[i][1]=3;
					f[i][2]=y;
					b[i][2]=2;
				}
			}
		}
		for(ll i=1;i<=n;i++){
			x=b[i][1];
			y=f[i][1];
			sum+=y;
			q[x].push({y-f[i][2],i});
			if(q[x].size()>m){
				q[b[i][2]].push({0,i});
				sum-=q[x].top().x;
				q[x].pop();
			}
		}
		io.write_ll(sum);
		putchar('\n');
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
