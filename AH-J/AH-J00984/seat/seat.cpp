#include<bits/stdc++.h>
using namespace std;
int a[110][110],s[10101];
int n,m,x,y,z,i,f;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>s[i];
    }
    z=s[0];
    sort(s,s+n*m);
    x=1;
    y=1;
    while(1+1==2){
        if(s[i]==z){
            cout<<x<<' '<<y;
            return 0;
        }
        if(f==0){
            if(x+1<=n) x++;
        else{
            x=1;
            if(y+1<=m)y++;
            f=!f;
            }  
        }      
        if(f==1){
            if(x-1>0) x--;
            else{
                x=1;
                if(y+1<=m)y++;
                f=!f;
            }
        }
        i++;
    }
    return 0;
}
