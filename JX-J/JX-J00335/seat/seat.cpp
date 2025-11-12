#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    if(x>y){
        return true;
    }else{
        return false;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    int mp[n*m]={0};
    for(int i=0;i<n*m;i++){
        cin>>mp[i];
    }
    int x=mp[0];
    sort(mp,mp+(n*m),cmp);
    int nx=1,ny=1;
    for(int i=0;i<n*m;i++){
        if(mp[i]==x){
            cout<<nx<<" "<<ny;
            break;
        }else{
            if(nx%2!=0){
                if(ny!=n){
                    ny++;
                }else{
                    ny=n;
                    nx++;
                }
            }else{
               if(ny!=1){
                    ny--;
               }else{
                    ny=1;
                    nx++;
               }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
