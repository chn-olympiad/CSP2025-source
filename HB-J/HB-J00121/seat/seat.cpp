#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int a[15][15]={0},s[1000]={0},s1=0;
int n,m;
cin>>n>>m;
int x=1,y=1;
for(int i=1;i<=n*m;i++){
    cin>>s[i];

}
s1=s[1];
sort(s+1,s+m*n+1);

for(int i=m*n;i>=1;i--){
    if(s[i]==s1){
        cout<<x<<" "<<y;
    }

    a[y][x]=s[i];
//    cout<<y<<" "<<x<<endl;
//    cout<<a[y][x]<<endl;
    if(y==1&&x%2==0){
        x++;
    }
    else if(y==m&&x%2==1)
    {
        x++;
    }
    else if(x%2==0){
        y--;
    }
    else if(x%2==1){
        y++;
    }

}
//cout<<endl;
//for(int i=1;i<=m;i++){
//for(int j=1;j<=n;j++){
//cout<<a[i][j]<<" ";
  //  }
    //cout<<endl;
//}
return 0;}
