#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int mp[n]={0};

    for(int i=0;i<n;i++){
        cin>>mp[i];
    }
    int num=0;
    if(n<=2){
        cout<<0;
    }else{
        if(mp[0]+mp[1]>mp[2]&&mp[1]+mp[2]>mp[0]&&mp[0]+mp[2]>mp[1]){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
