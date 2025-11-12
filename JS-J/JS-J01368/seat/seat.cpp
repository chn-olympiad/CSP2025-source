#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,rScore,rPos,c,r;
int sc[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //read
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>sc[i];
    //deal
    rScore=sc[1];
    sort(sc+1,sc+1+n*m);
    reverse(sc+1,sc+1+n*m);
    rPos=find(sc+1,sc+1+n*m,rScore)-sc;
    //cout<<rPos;
    //ans
    c=ceil(rPos/double(n));
    //cout<<ceil(rPos/double(n))<<endl;
    if(c%2==1){
        r=rPos%n;
        if(rPos%n == 0)
            r=m;
    }
    else
        r=c*n-rPos+1;
    cout<<c<<' '<<r;
    return 0;
}
