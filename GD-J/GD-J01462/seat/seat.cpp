#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int ans[N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int anssize=n*m;
    int num=0;
    for(int i=1;i<=anssize;i++){
        cin>>ans[i];
    }
    int xqcj=ans[1];
    for(int i=1;i<=anssize;i++){
        if(ans[i]>xqcj)num++;
    }
    int lie,hang;
    lie=(num-(num%n))/m+1;
    hang=num%n+1;
    if(lie%2==0)hang=n-hang+1;
    cout<<lie<<" "<<hang;
    return 0;
}

