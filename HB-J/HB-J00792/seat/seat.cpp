#include<bits/stdc++.h>
using namespace std;
int n,m,nm;
const int mx=105;
int a[mx];
int score,prize;
int ans1,ans2;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    for(int i=1;i<=nm;i++){
        cin>>a[i];
    }
    score=a[1];
    sort(a+1,a+1+nm);

    for(int i=nm;i>=1;i--){
        if(score==a[i])prize=nm-i+1;
    }
    //cout<<prize<<endl;
    if(prize%n==0){
        ans1=prize/n;
        if(ans1%2==1)ans2=n;
        else if(ans1%2==0)ans2=1;


    }else{
        ans1=(prize/n)+1;
        if(ans1%2==0) ans2=n-((prize-1)%n);
        if(ans1%2==1) ans2=prize%n;
    }

    cout<<ans1<<" "<<ans2;
    return 0;
}
/*
2 2
99 100 97 98
*/
