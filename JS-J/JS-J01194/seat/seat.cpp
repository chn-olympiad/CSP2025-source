#include <bits/stdc++.h>

using namespace std;
int n,m,a[105],score;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    score=a[1];
    sort(a+1,a+1+t,cmp);
    for(int i=1;i<=t;i++){
        if(a[i]==score){
            score=i;
            break;
        }
    }
    int x=(score-1)/n+1;
    cout<<x<<' ';
    if(x%2==0){
        cout<<n-((score-1)%n);
    }
    else{
        cout<<(score-1)%n+1;
    }
    return 0;
}
