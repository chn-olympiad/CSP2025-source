#include<bits/stdc++.h>
using namespace std;
const int N=1e1+5,M=1e1+5;
int n,m,me,leadme,someone,myseat,r,c;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&me);
    for(int i=2;i<=n*m;i++)
    {
        scanf("%d",&someone);
        if(someone>me)
            leadme++;
    }
    myseat=leadme+1;
    c=(myseat-1)/n+1;
    r=myseat%(n*2);
    if(r==0)
        r=1;
    else if(r>n)
        r=n*2-r+1;
    cout<<c<<" "<<r;
    return 0;
}
