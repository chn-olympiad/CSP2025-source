#include<bits/stdc++.h>
#define ll long long
using namespace std;

int m,n,a,b,c;//a=chengji b=dangqian chengji c=paimin
int ans1,ans2;

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m>>a;
    c=1;
    for(int i=1;i<m*n;i++){
        cin>>b;
        if(b>a)c++;
    }
    if(c%n==0)ans1=c/n;
    else ans1=c/n+1;
    if(ans1&1==1){
        if(c%n==0)ans2=n;
        else ans2=c%n;
    }
    else{
        if(c%n==0)ans2=1;
        else ans2=n+1-c%n;
    }
    cout<<ans1<<' '<<ans2<<endl;

    return 0;

}
