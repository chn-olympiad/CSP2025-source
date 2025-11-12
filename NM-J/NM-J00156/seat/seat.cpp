#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+10]={0};
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int c=1,r=1;
    for(int i=1;i<=n*m;i++){
        int maxx=-1,seat=-1;
        for(int j=1;j<=n*m;j++){
            if(a[j]>maxx){
                maxx=a[j];
                seat=j;

            }
        }
        //cout<<c<<" "<<r<<":"<<a[seat]<<endl;
        if(seat==1){
            cout<<c<<" "<<r;
            break;
        }
        a[seat]=-1;
        if(c%2!=0){
            if(r==n){
                c++;
            }else{
                r++;
            }
        }else{
            if(r==1){
                c++;
            }else{
                r--;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
