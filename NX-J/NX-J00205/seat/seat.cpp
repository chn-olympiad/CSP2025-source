#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[101]={0};
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int e,x=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[i]<a[i+1]){
                e=a[i];
                a[i]=a[i+1];
                a[i+1]=e;
            }
        }
    }
    int y=1;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                if(a[y]==x){
                    cout<<i<<" "<<j;
                }
                y++;
            }
        }else{
            for(int t=m;t>=1;t--){
                if(a[y]==x){
                    cout<<i<<" "<<t;
                }
                y++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
