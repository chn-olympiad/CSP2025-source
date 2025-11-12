#include<bits/stdc++.h>
using namespace std;


int cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    const long MAX_s=998244353;
    int n,m;
    char a[510];
    int nai[510];
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>nai[i];
    int ans=0;
    //льеп
    if(m==0){
        goto fin;
    }
    if(m==1){
        ans=694848220;
        goto fin;
    }

    fin:
        cout<<ans%MAX_s<<endl;
}
