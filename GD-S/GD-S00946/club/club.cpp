#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
priority_queue<pair<long long, pair<  long long, long long> > > q[10];
//                   ÊýÖµ     id    ÅÅÃû 
struct tt{
	long long x,id;
}a[100006][10];
bool cmp(tt x,tt y){
	return x.x>y.x;
}
bool p;
long long ans=0,mid;
void f(long long i,long long st){
	for(long long j=st;j<=3;j++){
		if(q[a[i][j].id].size()<mid){
			if(j+1>=3)q[a[i][j].id].push({-(a[i][j].x+1e9),{j,i}});
			else q[a[i][j].id].push({-(a[i][j].x-a[i][j+1].x),{j,i}});
			return;
		}
		long long z=-q[a[i][j].id].top().first;
		long long id=q[a[i][j].id].top().second.second;
		long long _p=q[a[i][j].id].top().second.first;
		if(a[id][_p+1].x-a[id][_p].x+a[i][j].x-a[i][j+1].x>0){
			q[a[i][j].id].pop();
			if(j+1>=3)q[a[i][j].id].push({-1e9,{j,i}});
			else q[a[i][j].id].push({-(a[i][j].x-a[i][j+1].x),{j,i}});
			f(id,_p+1);
			return;
		}
		
	}
}
void work(){
	long long n;
	ans=0;
	cin>>n;
	mid=n/2;
	for(long long i=1;i<=n;i++){
		cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
		for(long long j=1;j<=3;j++){
			p=0;
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+4,cmp);
		f(i,1);
	}
	for(long long i=1;i<=3;i++){
		while(!q[i].empty()){
			ans+=a[q[i].top().second.second][q[i].top().second.first].x;
			q[i].pop();
		}
	}
	cout<<ans;
}
int main(){
	op();
	long long T;
	cin>>T;
	while(T--){
		work();
		cout<<"\n";
	}
} 
