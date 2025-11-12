#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("seat3.in","r",stdin);
    freopen("seat3.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1000]={0};
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cj=a[1];
    int cnt=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==cj){
            cout<<i<<" "<<cnt;
        }
        else{
            cnt++;
        }
    }
    return 0;
}
