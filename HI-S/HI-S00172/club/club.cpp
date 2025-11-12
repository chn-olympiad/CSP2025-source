#include<bits/stdc++.h>
using namespace std;
map<string,string>k;
string l;
int n,m;
int t;
//int num=0;
int ans=0;
int vis[100001];
struct Node{
	int a,b,c;
	int id;
}p[1000001];
void dfs(int x,int a1,int b1,int c1,int num){
  if(x>n){
   ans=max(ans,num);
  // if(num==147325)  cout<<a1<<" "<<b1<<" "<<c1<<"\n";
   //if(num)
   return ;
  }
  for(int i=1;i<=3;i++){
  if(vis[x]==0){
    if(i==1&&a1<n/2){
    	vis[x]=1;
    	
    	dfs(x+1,a1+1,b1,c1,num+p[x].a);
    vis[x]=0;
	}
  else if(i==2&&b1<n/2){
    	vis[x]=1;
    	dfs(x+1,a1,b1+1,c1,num+p[x].b);
    vis[x]=0;
	}
	else {
		if(c1<n/2){
    	vis[x]=1;
    	dfs(x+1,a1,b1,c1+1,num+p[x].c);
    vis[x]=0;
	}	}
  }}
}
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  //t=1;
  while(t--){
  	cin>>n;
  	memset(vis,0,sizeof(vis));
  	  ans=0;
  	bool k1=true,k2=true;
  	for(int i=1;i<=n;i++)  {
	  cin>>p[i].a>>p[i].b>>p[i].c;
	  p[i].id=i;
	if(p[i].c!=0)  k2=false;
	if(p[i].b!=0)  k1=false;
  }
  if(n<=10){
  dfs(1,0,0,0,0);
  cout<<ans<<"\n";}
  else if(k1&&k2){
  	vector<int>ax;
  	for(int i=1;i<=n;i++){
  		ax.push_back(p[i].a);
	  }
	  sort(ax.begin(),ax.end());
	  for(int i=0;i<n/2;i++)  ans+=ax[i];
	  cout<<ans;
  }
}
   fclose(stdin);
   fclose(stdout);
   return 0;
}
