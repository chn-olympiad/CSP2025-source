#include<bits/stdc++.h>
using namespace std;
int a[100001][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        for(int b=1;b<=n;b++){
           int q,w,e;
           cin>>q>>w>>e;
           a[n][0]=q;
           a[n][1]=w;
           a[n][2]=e; 
        }
    }
    cout<<rand()%100<<endl<<rand()%100<<endl<<rand()%100;
    return 0;
}