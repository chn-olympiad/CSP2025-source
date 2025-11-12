#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
//-----------------------------------
int t,n,a[N][3],b[3];
int dfs(int i,int s){
	//cout<<i<<" "<<s<<' '<<b[0]<<' '<<b[1]<<' '<<b[2]<<'\n';
	int Max=-10;
	if(i>n)return s;
	for(int j=0;j<3;j++){
		if(b[j]+1<=n/2){
			s+=a[i][j];
			b[j]++;
			Max=max(Max,dfs(i+1,s));
			b[j]--;
			s-=a[i][j];
		}
	}
	return Max;
}
void fix(){
	memset(a,0,sizeof a);
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	cout<<dfs(0,0)<<'\n';
}
//-----------------------------------
struct Node{
	int id;
	int v;
	int z;
}c[N];
int sum[3],h,ans;
bool vis[N];
bool cmp(Node x,Node y){
	//cout<<a.id<<' ';
	return x.v>y.v;
}
void input(){
	for(int i=0;i<n;i++){
		cin>>c[i*3].v>>c[i*3+1].v>>c[i*3+2].v;
		c[i*3].z=0;
		c[i*3+1].z=1;
		c[i*3+2].z=2;
		c[i*3].id=c[i*3+1].id=c[i*3+2].id=i;
	}
}
void fix1(){
	h=n/2;
	ans=0;
	sum[0]=sum[1]=sum[2]=0;
	memset(b,0,sizeof b);
	memset(vis,0,sizeof vis);
	input();
	sort(c,c+3*n,cmp);
	for(int i=0;i<n*3;i++){
		//cout<<c[i].id<<' '<<c[i].v<<' '<<c[i].z<<'\n';
		if(!vis[c[i].id]&&sum[c[i].z]<h){
			sum[c[i].z]++;
			ans+=c[i].v;
			vis[c[i].id]=1;
		}
	}
	cout<<ans<<'\n';
}
//-----------------------------------
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=10){
			fix();
		}
		else{
			//fix1();
		}
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
