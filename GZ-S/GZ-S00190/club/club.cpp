//GZ-S00190 贵阳市第十七中学 徐廷蔚 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct node{
	int a,b,c,id;
}f[100005];
bool vis[100005];
int t;
long long sum=0;
bool cmp(node x,node y){
	x.a>y.a;
}
bool cmp1(node x,node y){
	x.b>y.b;
}
bool cmp2(node x,node y){
	x.c>y.c; 
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			f[i].id=i;
		}
		sort(f+1,f+1+n,cmp);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt<=n/2 && f[i].b<f[i].a && f[i].c<f[i].a){
				vis[f[i].id]=1;
				sum+=f[i].a;
				cnt++;
			}
		}
		sort(f+1,f+1+n,cmp1);
		cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt<=n/2 && !vis[f[i].id] && f[i].a<f[i].b && f[i].c<f[i].b){
				vis[f[i].id]=1;
				sum+=f[i].b;
				cnt++; 
			}
		}
		sort(f+1,f+1+n,cmp2);
		cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt<=n/2 && !vis[f[i].id] && f[i].b<f[i].c && f[i].a<f[i].c){
				vis[f[i].id]=1;
				sum+=f[i].c;
				cnt++;
			}
		}
		cout<<sum<<"\n";
		sum=0;
		memset(vis,0,sizeof vis);
	}
	return 0;
}
