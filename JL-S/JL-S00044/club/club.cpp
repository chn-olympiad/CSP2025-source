#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,q,w,e,s1=0,s2=0,s3=0,t=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q>>w>>e;
        s1=s1+q;
        s2=s2+w;
        s3=s3+e;
    }
    if(s1>s2){
        t=s1;
        s1=s2;
        s2=s3;
    }
    cout<<t<<' '<<s1<<' '<<s2;
    return 0;}
