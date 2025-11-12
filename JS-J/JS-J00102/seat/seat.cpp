#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a[105],cnt,x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a1;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
        if(a[i]>a1)cnt++;
    }
    while(cnt--){
        if(x%2){
            if(y!=n)y++;
            else x++;
        }else{
            if(y!=1)y--;
            else x++;
        }
    }
    cout<<x<<" "<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}