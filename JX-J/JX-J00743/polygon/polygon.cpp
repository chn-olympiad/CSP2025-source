#include<bits/stdc++.h>
using namespace std;
int s[100001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdin);
    int m,sum=0;
    cin>>m;
    if(m<3){
        cout<<0;
    }
    for(int i=1;i<=m;i++){
        cin>>s[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            sum+=s[i];
        }
    }
    sum=sum-s[2];
    cout<<sum;
    return 0;
}
