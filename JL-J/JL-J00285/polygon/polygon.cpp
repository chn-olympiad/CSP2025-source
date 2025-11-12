#include<bits/stdc++.h>
using namespace std;
int n,a[5005],t=0;
void mysum(int x,int step,long long sum,int mx,int y){
    if(step==x){
        if(sum>mx*2){
            t++;
            if(t==998244353){
                t=0;
            }
        }
        return;
    }
    for(int i=y;i<=n-step+x;i++){
        mysum(x,step+1,sum+a[i],max(mx,a[i]),i+1);
    }

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
            mysum(i,1,0,-1,1);
    }
    cout<<t;
    return 0;
}
