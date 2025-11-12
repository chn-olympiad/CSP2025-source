#include<bits/stdc++.h>
using namespace std;
bool cm=1;
int a1,n,m,s,p;
int sc[105];
int ans1,ans2;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ////
    cin>>n>>m;
    cin>>a1;
    sc[0]=a1;
    for(int i=1;i<n*m;i++){
        cin>>sc[i];
    }
    sort(sc,sc+n*m,cmp);

    for(int i=0;i<n*m;i++){
        if(sc[i]==a1)p=i+1;
    }
    //cout<<"p="<<p<<endl;

    /*for(int i=0;i<n*m;i++){
        cout<<sc[i]<<" ";
    }
    cout<<endl;*/
    if(p%n==0)ans1=p/n;
    else ans1=p/n+1;
    //ans1=p/n+1;
    //cout<<"ans1="<<ans1<<endl;

    if(ans1%2==0)cm=0;
    else cm=1;

    if(cm==1){
        ans2=p-((ans1-1)*n);
    }else{
        ans2=n-(p-((ans1-1)*n))+1;
    }

    cout<<ans1<<" "<<ans2;
    return 0;
}