#include<bits/stdc++.h>
using namespace std;
int score[100];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,t;
    cin>>n>>m;
    for(int i=0;i<m*n;++i)
        cin>>score[i];
    int a=score[0];
    sort(score,score+m*n);
    for(t=0;t<n*m;++t){
        if(score[t]==a)
            break;
    }
    t=m*n-t-1;
    c=t/n+1;
    if(c%2==1)
        r=t%n+1;
    else
        r=n-t%n;
    cout<<c<<' '<<r;
    return 0;
}
