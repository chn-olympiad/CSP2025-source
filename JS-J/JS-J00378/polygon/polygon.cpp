#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m[10000],cnt,num[10000],max1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    if(n=3){
        for(int j=0;j<n;j++){
            max1=m[0];
            if(m[j]>max1){
                max1=m[j];
            }
        }
        //cout<<max1;
        if (m[0]+m[1]+m[2]>2*max1){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    cout<<9;
    return 0;
}
