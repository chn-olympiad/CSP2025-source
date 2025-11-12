#include<bits/stdc++.h>
using namespace std;
int n,m,f[120],R,r,c=1;
bool flag;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m*n;i++){
        cin>>f[i];
    }
    R=f[0];
    sort(f,f+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(flag){
            r--;
            if(r==0){
                r++;
                flag=0;
                c++;
            }
        }
        else{
            r++;
            if(r==n+1){
                flag=1;
                c++;
                r--;
            }
        }
        if(f[i]==R){
            break;
        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
