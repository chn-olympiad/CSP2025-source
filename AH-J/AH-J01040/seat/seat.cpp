#include<bits/stdc++.h>
using namespace std;
int n,m,r;
struct node{
   int h,z;
};
int a[111111];
node s[111111];
int cmp(int a,int b){
   return a>b;
}
int dfs(int x,int y,int id){
    if(id==n*m){
        return 0;
    }
    s[a[id]]={x,y};
    if(x%2==1&&y==n){
        dfs(x+1,y,id+1);
    }
    else if(x%2==0&&y==1){
        dfs(x+1,y,id+1);
    }
    else if(x%2==1){
       dfs(x,y+1,id+1);
    }
    else{
       dfs(x,y-1,id+1);
    }
    return 0;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
        cin>>a[i];
}
r=a[1];
sort(a+1,a+1+n*m,cmp);
dfs(1,1,1);
cout<<s[r].h<<" "<<s[r].z;
return 0;
}
