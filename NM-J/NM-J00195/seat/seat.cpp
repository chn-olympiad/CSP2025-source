#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //I love you CCF;
    //I can try this one;
    int m,n;//n hang;m lie;
    cin>>n>>m;
    int deshu=0;
    int mp[105];
    for(int i=0;i<n*m;i++){
        cin>>mp[i];
    }
    int R=mp[0];
    for(int i=0;i<n*m-1;i++){
        for(int j=0;j<n*m-i-1;j++){
            if(mp[j]<mp[j+1]){
                int temp=mp[j];
                mp[j]=mp[j+1];
                mp[j+1]=temp;
            }
        }
    }
    for(int i=0;i<m*n;i++){
        if(mp[i]==R){
            deshu=i+1;
        }
    }
    //2 2 99 98 100 97
    //2 2 98 99 100 97
    int ans=(deshu-(deshu%n))/n;
    if(deshu%n!=0){
        ans=ans+1;
    }
    int ret=deshu%n;
    if(ret==0){
        ret=n;
    }
    if(ans%2==0){
        ret=n-ret+1;
    }
    cout<<ans<<" "<<ret<<endl;
    return 0;
}
