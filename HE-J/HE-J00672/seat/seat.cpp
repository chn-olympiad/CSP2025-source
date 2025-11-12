#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1001],b=0,ans=0;
    int k=0;
    int x=0,y=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    b=a[0];
    for(int i=0;i<n*m;i++){
        for(int j=i+1;j<n*m;j++){
            if(a[i]<a[j]){
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    for(int i=0;i<m*n;i++){
        if(a[i]==b){
            ans=i+1;
            break;
        }
    }
    x=ans/n;
    if(ans%n>0){
        x+=1;
    }

    if(x==1){
        y=ans;
    }else{
        if(x%2==0){
            y=n+x*n+1-ans-x;
        }else{
            y=ans-x*n+x;
        }
    }
    cout<<x<<" "<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
