#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,c=1,d;
    cin>>x>>y;
    int n[x*y+1];
    for(int i=1;i<=x*y;i++)cin>>n[i];
    d=n[1];
    sort(n+1,n+1+x*y);
    for(int i=1;i<=x*y/2;i++){
        int ans=n[i];
        n[i]=n[x*y-i+1];
        n[x*y-i+1]=ans;
    }

    for(int i=1;i<=x;i++){
        if(i%2==1){
            for(int j=1;j<=y;j++){
                if(n[c]==d){
                    cout<<i<<" "<<j;
                    return 0;
                }
                else c++;
            }
        }
        if(i%2==0){
            for(int j=y;j>=1;j--){
                if(n[c]==d){
                    cout<<i<<" "<<j;
                    return 0;
                }
                else c++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
