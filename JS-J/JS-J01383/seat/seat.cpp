#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10111];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int N,m;
    cin>>N>>m;
    int n=N*m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int r=a[1];
    int id;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(a[i]==r) id=i;
    }
    if(id%N==0){
        int x=id/N,y=N;
        cout<<x<<" "<<y<<endl;
        return 0;
    }
    int x=(id+N)/N,y;
    if(x%2==0){
        y=N-id%N+1;
    }
    if(x%2==1) y=id%N;
    cout<<x<<" "<<y<<endl;
    return 0;
}
/*
    ******    ******          
    *     *   *     *      *         *
    *     *   *     *      *         *
    ******    ******    *******   ******* 
    *  **     *            *         *
    *   **    *            *         *
    *    **   *
    duo gei fen!
Love CCF
*/