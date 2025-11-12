#include <bits/stdc++.h>
using namespace std;
int n,m;
int grade[200];
int seat[200][200],x,y,cnt,rgrade;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>grade[i];
}
rgrade=grade[1];
sort(grade+1,grade+1+n*m);
x=1,y=1;
cnt=n*m;
while(n*m){
    seat[x][y]=grade[cnt];
    if(grade[cnt]==rgrade)
    break;
    cnt--;
    if(x%2==1)
    y++;
    else
    y--;
    if(y>m||y<1){
        if(x%2==1){
        y=m;
        }else{
          y=1;
        }
        x++;
    }
}
cout<<x<<" "<<y;
return 0;
}
