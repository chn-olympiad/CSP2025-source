#include<bits/stdc++.h>
using namespace std;
int n,m,s,k,x,y,t;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    s=n*m;
    for(int i=1;i<=s;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+s+1);
    x=1;y=1;t=0;
    while(1){
        t++;
        if(a[s-t+1]==k){
            cout<<x<<" "<<y;
            return 0;
        }
        if(x%2==0&&y==1||x%2==1&&y==n)x++;
        else if(x%2==0)y--;
        else y++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
