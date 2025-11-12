#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int x,y,c;
}a[200];
struct Node1{
	int h;
	int l[2000];
}cns[2000];
bool cmp[200][200];
bool cmp1(Node x,Node y){
	return x.c<y.c;
}
bool cnds[2000];
int ans=0;
int minn=0x3f3f3f3f;
void dfs(int dn){
	bool df=true;
	for(int i=1;i<=n;i++){
		if(!cnds[i]){
			df=false;
		}
	}
	if(df){
		if(minn>ans){
			minn=ans;
		}
		ans=0;
	}else{
		for(int i=1;i<=m;i++){
			if(a[i].x==dn||a[i].y==dn){
				if(a[i].x==dn){
					cnds[a[i].y]=true;
					ans+=a[i].c;
					dfs(a[i].y);
					ans-=a[i].c;
					cnds[a[i].y]=false;
				}else{
					cnds[a[i].x]=true;
					ans+=a[i].c;
					dfs(a[i].x);
					ans-=a[i].c;
					cnds[a[i].x]=false;
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].c; 	
	}
	for(int i=1;i<=k;i++){
		cin>>cns[i].h;
		for(int j=1;j<=n;j++){
			cin>>cns[i].l[i];
		}
	}
	sort(a+1,a+m+1,cmp1);
	cnds[a[1].x]=true;
	dfs(a[1].x);
	cout<<minn<<endl;
	return 0;
} 
