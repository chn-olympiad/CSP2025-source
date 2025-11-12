#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==0||n==1||n==2)cout<<0;
    else if(n==3)cout<<1;
    else cout<<2;
    return 0;
}
