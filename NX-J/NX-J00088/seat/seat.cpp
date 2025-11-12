#include <bits/stdc++.h>
using namespace std;
long long n,m,s[105],lie=0,hang=0,pm,fs;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>s[i];
    fs=s[1];
    sort(s+1,s+n*m+1);
    for(int i=n*m;i>=1;i--) if(s[i]==fs) pm=n*m-i+1;
    while(pm-n>=0)
    {
        pm-=n;
        lie++;
    }
    if(pm==0) lie--;
    else lie++;
    if(lie%2==0) hang=n-pm+1;
    else hang=pm;
    cout<<lie<<" "<<hang;
}
