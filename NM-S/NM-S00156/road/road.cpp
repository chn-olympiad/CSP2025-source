#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,NN=1e6+5;
 int a[N][N],b[N];
 struct stu{
 int u,v,w;};
 void bfs(){
     queue <int> q;
     int x=1,y=1;
     q.push(1);
     while(!q.empty()){
        for(int i=1;i<=4;i++){
            if(i!=q.front()){
                q.push(i);
            }
        }
     }
 }
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int m,n,k=0;
    cin>>n>>m>>k;
    int x,y,z,gz;
   for(int i=0;i<m;i++){
    cin>>x>>y>>z;
    if(a[x][y]==0||a[x][y]>z){
        a[x][y]=z;
        a[y][x]=z;
    }
   }
    for(int i=0;i<k;i++){
        cin>>gz;

    for(int j=1;j<=n;j++){
        cin>>b[j];
    }
    }
for(int i=1;i<n;i++){

}















	return 0;
}
