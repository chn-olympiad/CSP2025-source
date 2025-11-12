#include<bits/stdc++.h>
using namespace std;
struct people{int x,y,z;}a[100010];
int maxx,n,q[100010];
void DFS(int id,int sum,int x,int y,int z){
	if(x>n/2)return ;
	if(y>n/2)return ;
	if(z>n/2)return ;
	if(sum+q[n]-q[id-1]<maxx)return ;
	if(id==n+1){
		maxx = max(maxx,sum);
		return ;
	}
	DFS(id+1,sum+a[id].x,x+1,y,z);
	DFS(id+1,sum+a[id].y,x,y+1,z);
	DFS(id+1,sum+a[id].z,x,y,z+1);
	return ;
}
bool cmp1(people xx,people yy){return xx.x>yy.x;}
void solve(){
	bool xx = 0,yy = 0,zz = 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].x)xx = 1;
		if(a[i].y)yy = 1;
		if(a[i].z)zz = 1;
		q[i] = q[i-1]+max(a[i].x,max(a[i].y,a[i].z));
	}
	if(n<=30){
		maxx = 0;
		DFS(1,0,0,0,0);
		cout<<maxx<<endl;
	}
	else if(xx&&!yy&&!zz){
		sort(a+1,a+1+n,cmp1);
		int sum = 0;
		for(int i = 1;i<=n/2;i++)sum = sum+a[i].x;
		cout<<sum;
	}
	else{
		maxx = 0;
		DFS(1,0,0,0,0);
		cout<<maxx<<endl;
	}
	return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}

