#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

const int N=100010;

priority_queue<pii>q1;
priority_queue<pii>q2;
priority_queue<pii>q3;
int n;
int a[N][4];

int mx(int a,int b,int c){
	return max(a,max(b,c));
}
int mn(int a,int b,int c){
	return min(a,min(b,c));
}
int mid(int a,int b,int c){
	return a+b+c-mx(a,b,c)-mn(a,b,c);
}


void sel(int d1,int d2,int d3,int idx){
	if(mx(d1,d2,d3)==d1)q1.push(make_pair(mid(d1,d2,d3)-d1,idx));
	else if(mx(d1,d2,d3)==d2)q2.push(make_pair(mid(d1,d2,d3)-d2,idx));
	else q3.push(make_pair(mid(d1,d2,d3)-d3,idx));
}

void solve(){
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1,d1,d2,d3;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		sel(a[i][1],a[i][2],a[i][3],i);
		if(q1.size()>n/2){
			int x=q1.top().se;
			if(q1.top().fi+a[i][1]>0)sel(-114514,a[x][2],a[x][3],x);
			q1.pop();
		}
		else if(q2.size()>n/2){
			int x=q2.top().se;
			if(q2.top().fi+a[i][2]>0)sel(a[x][1],-114514,a[x][3],x);
			q2.pop();
		}
		else if(q3.size()>n/2){
			int x=q3.top().se;
			if(q3.top().fi+a[i][3]>0)sel(a[x][1],a[x][2],-114514,x);
			q3.pop();
		}
	}
	int sum=0;
	while(!q1.empty()){
		sum+=a[q1.top().se][1];
		q1.pop();
	}
	while(!q2.empty()){
		sum+=a[q2.top().se][2];
		q2.pop();
	}
	while(!q3.empty()){
		sum+=a[q3.top().se][3];
		q3.pop();
	}
	cout<<sum<<endl;
	return;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}