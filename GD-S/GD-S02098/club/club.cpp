#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
long long sum;
int t,n;
int a[10];
struct st{
	int x,y;
	int i,j;
	friend bool operator <(st a,st b){
		return a.x-a.y>b.x-b.y;
	}
};

void solve(){
	priority_queue<st>q;
	sum=0;
	a[1]=a[2]=a[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		int xx=1,yy=2,zz=3;
		if(x<y)swap(x,y),swap(xx,yy);
		if(y<z)swap(y,z),swap(yy,zz);
		if(x<z)swap(x,z),swap(xx,zz);
		a[xx]++;
		sum+=x;
		q.push({x,y,xx,yy});	
	}
	int sw=0;
	for(int i=1;i<=3;i++){
		if(a[i]>n/2)sw=i;
	}
	if(sw){
		while(a[sw]>n/2){
			st now=q.top();
			q.pop();
			a[now.i]--,a[now.j]++;		
			sum=sum-now.x+now.y;	
		}
	}
	cout<<sum<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
