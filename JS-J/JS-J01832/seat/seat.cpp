#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,a1;
int a[10000],s[1000][1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++){
        scanf("%d",&a[i]);
    }
    a1=a[0];
   sort(a,a+n*m);
    for(int i=n*m-1;i>=0;i--){
        s[x][y]=a[i];
        if(s[x][y]==a1){
            cout<<x<<" "<<y;
            return 0;
        }
        if(x%2!=0&&y==n){
            x++;
            continue;
        }
        if(x%2==0&&y==1){
            x++;
            continue;
        }
        if(x%2!=0){
            y++;
        }else{
            y--;
        }

    }

    return 0;
}
