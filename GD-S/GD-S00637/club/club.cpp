#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#define ll long long
using namespace std;
int n,t;
ll ans;
int a[100005][4];
int mx[100005]={0};
struct node{
	int a,b,c;
}tm[100005];
bool cmp(node x,node y){
	int sx=x.a+x.b+x.c;
	int sy=y.a+y.b+y.c;
	return sx>sy;
}
void dfs(ll cnt,int i,int ca,int cb,int cc){
	//cout<<cnt<<" ";
	//if(cnt>=mx[i])mx[i]=cnt;
//	else return;
	if(i==n+1){
		ans=max(ans,cnt);
		//printf("cnt%d a%d b%d c%d\n",cnt,ca,cb,cc);
		return ;
	}
	if(ca+1<=n/2)dfs(cnt+a[i][1],i+1,ca+1,cb,cc);
	if(cb+1<=n/2)dfs(cnt+a[i][2],i+1,ca,cb+1,cc);
	if(cc+1<=n/2)dfs(cnt+a[i][3],i+1,ca,cb,cc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>tm[i].a>>tm[i].b>>tm[i].c;
		}
		sort(tm+1,tm+n+1,cmp);
		for(int i=1;i<=n;i++){
			a[i][1]=tm[i].a;
			a[i][2]=tm[i].b;
			a[i][3]=tm[i].c;
		}
		dfs(0,1,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
