#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
int n,m,k,jk,sum,num,cnt,tot;ll ans;
int head[N],dis[N],vis[N],wis[N],kis[N],f[N];

void read(int & x){
	x=0;int ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(ll x){
	if(x<0){x=-x;
		putchar('-');
	}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));
}

struct P{
	int x,y,z;
}v[N];

struct Q1{
	int x,y,z,id;
	bool operator<(const Q1& A)const{
		return max(A.y,A.z)+x>max(y,z)+A.x;
	}
};

struct Q2{
	int x,y,z,id;
	bool operator<(const Q2& A)const{
		return max(A.x,A.z)+y>max(x,z)+A.y;
	}
};

struct Q3{
	int x,y,z,id;
	bool operator<(const Q3& A)const{
		return max(A.x,A.y)+z>max(x,y)+A.z;
	}
};

priority_queue<Q1> q1;
priority_queue<Q2> q2;
priority_queue<Q3> q3;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(jk);while(jk--){
		read(n);
		for(int i=1;i<=n;i++){
			read(v[i].x),read(v[i].y),read(v[i].z);
			if(v[i].x>=v[i].y&&v[i].x>=v[i].z){
				q1.push((Q1){v[i].x,v[i].y,v[i].z,i});
				while((int)q1.size()>n/2){
					Q1 z=q1.top();q1.pop();
					if(max(z.y,z.z)==z.y) q2.push((Q2){z.x,z.y,z.z,z.id});
					else q3.push((Q3){z.x,z.y,z.z,z.id});
				}
			}else if(v[i].y>=v[i].x&&v[i].y>=v[i].z){
				q2.push((Q2){v[i].x,v[i].y,v[i].z,i});
				while((int)q2.size()>n/2){
					Q2 z=q2.top();q2.pop();
					if(max(z.x,z.z)==z.x) q1.push((Q1){z.x,z.y,z.z,z.id});
					else q3.push((Q3){z.x,z.y,z.z,z.id});
				}
			}else{
				q3.push((Q3){v[i].x,v[i].y,v[i].z,i});
				while((int)q3.size()>n/2){
					Q3 z=q3.top();q3.pop();
					if(max(z.x,z.y)==z.x) q1.push((Q1){z.x,z.y,z.z,z.id});
					else q2.push((Q2){z.x,z.y,z.z,z.id});
				}
			}
		}
//		wk(q1.size()),wk(q2.size()),wh(q3.size());
		while(!q1.empty()) ans+=q1.top().x,q1.pop();
		while(!q2.empty()) ans+=q2.top().y,q2.pop();
		while(!q3.empty()) ans+=q3.top().z,q3.pop();
		wh(ans);ans=0ll;
	}
	return 0;
}/*
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

18
4
13

*/
