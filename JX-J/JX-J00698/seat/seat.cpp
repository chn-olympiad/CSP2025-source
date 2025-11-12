#include<bits/stdc++.h>

using namespace std;
const int N=105;
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>a[1];
    int score_R=a[1],p_R=1;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>score_R)p_R++;
    }
    int c,r;
    r=p_R/n;
    int re_p=p_R-r*n;
    if(re_p!=0)r++;
    if(r%2==1){
        c=p_R-(r-1)*n;
    }
    else{
        c=n-p_R+(r-1)*n+1;
    }
    cout<<r<<" "<<c;
    return 0;
}

