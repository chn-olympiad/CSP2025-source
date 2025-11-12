#include<bits/stdc++.h>
using namespace std;
const int N=100055;
int n,T;
struct node{
	int x,y,z,i,t;
}a[N];

bool cmp1(node xx,node yy){
	return xx.x>yy.x;
}

int vis[N];//ng 

long long dfs(int s1,int s2,int s3,int p){
	long long tt=0;
	if(p>n)return 0;
	if(s1<n/2)tt=max(tt,dfs(s1+1,s2,s3,p+1)+a[p].x);       
	if(s2<n/2)tt=max(tt,dfs(s1,s2+1,s3,p+1)+a[p].y);
	if(s3<n/2)tt=max(tt,dfs(s1,s2,s3+1,p+1)+a[p].z);
	return tt;
}


int f1=0,f2=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	int s[4],t[4];
	while(T--){
		s[1]=0,s[2]=0,s[3]=0;
		t[1]=1,t[2]=1,t[3]=1;
		for(int i=1;i<=n;i++)vis[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y)f1=1;
			if(a[i].z)f2=1;
			a[i].i=i,a[i].t=0;
		}
		if(n<=30){
			cout<<dfs(0,0,0,1)<<endl;
		}
		else if(f1==0&&f2==0){
			sort(a+1,a+1+n,cmp1);
			long long ans;
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<endl;
		}
		else cout<<0;
	}
	
	
	
	return 0;
}


