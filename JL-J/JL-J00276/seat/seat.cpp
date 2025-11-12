#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,me,cnta,cnt=1;
    cin>>n>>m;
    cnta=n*m;
    int other[cnta];
    cin>>me;
    for(int i = 1;i <= cnta-1; i++)
        cin>>other[i];
    for(int i = 1;i <= cnta-1; i++)
    {
        if(other[i]>me) cnt++;
    }
    int nm,mm;
    mm=(cnt-1)/n+1;
    if(mm%2==1) nm=(cnt-1)%n+1;
    if(mm%2==0) nm=n-((cnt-1)%n);
    cout<<mm<<' '<<nm;
    return 0;
}
