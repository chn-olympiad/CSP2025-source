#include<bits/stdc++.h>
using namespace std;
int a,q[5010],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>q[i];
    }
    sort(q+1,q+a+1);
    if(q[1]+q[2]>q[3])ans++;
    cout<<ans;
    return 0;
}
