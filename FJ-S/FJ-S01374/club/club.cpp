#include<bits/stdc++.h>
#define ll long long
#define N 10010
using namespace std;
ll n,m,T,num[4],ans=0;
struct node{
	ll t,a,b,c,id,nw,nt;
}no;
bool operator < (node x,node y){
	return x.t<y.t;
}
node yun(node x){
	if(x.a>=x.b&&x.a>=x.c){
		ans+=x.a;
//		cout<<x.a<<" ";
		x.nw=1;
		if(x.b>=x.c)x.nt=2,x.t=x.b-x.a;
		else x.nt=3,x.t=x.c-x.a;
		return x;
	}
	if(x.b>=x.a&&x.b>=x.c){
		ans+=x.b;
//		cout<<x.b<<" ";
		x.nw=2;
		if(x.a>=x.c)x.nt=1,x.t=x.a-x.b;
		else x.nt=3,x.t=x.c-x.b;
		return x;
	}
	if(x.c>=x.a&&x.c>=x.b){
		ans+=x.c;
//		cout<<x.c<<" ";
		x.nw=3;
		if(x.a>=x.b)x.nt=1,x.t=x.a-x.c;
		else x.nt=2,x.t=x.b-x.c;
		return x;
	}
	return x;
}
node nxt(node x){
	ans+=x.t;
//	cout<<x.t<<" ";
	if(x.nt==1){
		x.nw=1;
		if(x.b>=x.c)x.nt=2,x.t=x.b-x.a;
		else x.nt=3,x.t=x.c-x.a;
		return x;
	}
	if(x.nt==2){
		x.nw=2;
		if(x.a>=x.c)x.nt=1,x.t=x.a-x.b;
		else x.nt=3,x.t=x.c-x.b;
		return x;
	}
	if(x.nt==3){
		x.nw=3;
		if(x.a>=x.b)x.nt=1,x.t=x.a-x.c;
		else x.nt=2,x.t=x.b-x.c;
		return x;
	}
	return x;
}
priority_queue<node>q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll i;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(i=1;i<=3;i++){
			while(num[i]){
				num[i]--;
				q[i].pop();
			}
		}
		for(i=1;i<=n;i++){
			cin>>no.a>>no.b>>no.c;
			no.id=i;
			no=yun(no);
			num[no.nw]++;
			q[no.nw].push(no);
		}
		for(i=1;i<=3;i++){
			while(num[i]>n/2){
//				cout<<i<<" ";
				no=q[i].top(),q[i].pop();
				num[i]--;
//				cout<<no.nw<<" "<<no.nt<<" ";
				no=nxt(no);
//				cout<<no.nw<<"\n";
				num[no.nw]++;
				q[no.nw].push(no);
			}
		}
//		cout<<"\n";
		cout<<ans<<"\n";
	}
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
