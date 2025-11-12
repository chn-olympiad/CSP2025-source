#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e5;
int a[N];
struct Node{
  int l,r;
};
bool cmp(Node a,Node b){
  if(a.l!=b.l)return a.l<b.l;
  else return a.r<b.r;
}
vector<Node>ans;
int maxn=0;
int main(){
	
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  cin>>n>>k;
  for(int i=1;i<=n;i++){
   cin>>a[i];
  }
  for(int i=1;i<=n;i++){
  int x=a[i];
     if(x==k) ans.push_back({i,i});
   for(int j=i+1;j<=n;j++){
   x=(x^a[j]);
   //cout<<x<<" ";
   if(x==k) ans.push_back({i,j});
   }
  }
 // sort(ans.begin(),ans.end(),cmp);
  int len=ans.size();
  for(int i=0;i<len;i++){
    int num=1;
    int l1=ans[i].l,r1=ans[i].r;
    //cout<<l1<<" "<<r1<<endl;
    for(int j=i+1;j<len;j++){
    if(ans[j].l>l1&&ans[j].r>r1) {num++;
    l1=ans[j].l,r1=ans[j].r;}
    
    }
    maxn=max(maxn,num);
  }
  cout<<maxn;
  fclose(stdin);
  fclose(stdout);
  return 0; 
}

