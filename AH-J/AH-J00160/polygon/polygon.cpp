#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,x[5010],v,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sort(x+1,x+1+n);
    for(int i=1;i<=n;i++){
        int h=0,v=i;
        for(int j=1;j<=v;j++){
            for(int k=1;k<=v-2;k++){
                h+=x[j];
            }
            if(h*2>x[j]){
                cnt++;
            }
        }
    }
    cout<<cnt%998244353;
    return 0;
}
