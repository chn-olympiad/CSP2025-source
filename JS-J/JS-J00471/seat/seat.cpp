#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n,m,t[20],a[20][20];
bool ud;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x=1,y=1;
    for(int i=1;i<=n*m;i++) cin>>t[i];
    ans=t[1];
    sort(t+1,t+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        a[x][y]=t[i];
        if(ud==0) x++;
        else x--;
        if(i%n==0&&i/n%2==1){
            y++;
            x--;
            ud=1;
        }
        else if(i%n==0&&i/n%2==0){
            y++;
            x++;
            ud=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==ans){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
/*
daily
11.1 Saturday cloudy
8:20 ate too much
8:30 start
T1 is easy
8:36 T1 AC
T2 is easy too
8:50 T2 AC
T3 is difficult
Maybe can cheat 25 points?
9:30 T4
I cant cheat any ponts
9:50 Use freopen
10:00 T1 may TLE?(Example4 cant be opened,1MB???)
10:05 Use jishu sort in T1,O(10n)
10:10 Write daily
10:15 I found that my name of T4 is wrong!
Bored
220 points?
My English is too bad;
I got 81 points in English month exam,138/147 mingci;
*/
