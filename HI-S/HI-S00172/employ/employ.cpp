#include<bits/stdc++.h>
using namespace std;
map<string,string>k;
string l;
int n,m;
int w[10010],vis[10010],c[10010],step[10010],ans=0;
void dfs(int x){
  if(x>n){
   int num=0,sum=0;
   for(int i=1;i<=n;i++){
   //cout<<sum;
    if(sum<c[step[i]]&&l[i-1]=='1') num++;
    else {sum++;}
   }
   //cout<<"\n";
   if(num>=m)  ans++;
   return ;
  }
  for(int i=1;i<=n;i++){
  if(vis[i]==0){
    vis[i]=1;
    step[x]=i;
    //cout<<1;
    dfs(x+1);
    vis[i]=0;
  }}
}
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  cin>>n>>m;
  cin>>l;
  //int len=l.size();
  /*for(int i=0;i<len;i++){
     w[i+1]=w[i]+(l[i]=='0');
  }*/
  for(int i=1;i<=n;i++)  cin>>c[i];
  dfs(1);
  cout<<ans;
   fclose(stdin);
   fclose(stdout);
   return 0;
}
