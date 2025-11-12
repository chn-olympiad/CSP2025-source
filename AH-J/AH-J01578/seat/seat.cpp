#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

typedef long long ll;
typedef double db;

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int N,M;
    cin>>N>>M;
    vector<int> A(N*M+1,0);
    rep(i,1,N*M) cin>>A[i];
    int a1=A[1];
    sort(A.begin()+1,A.end(),greater<int>());
    int x=1,y=0;
    rep(i,1,N*M)
    {
        if((y%2==1&&x==N)||(y%2==0&&x==1)) y++;
        else{
            if(y%2==1) x++;
            else x--;
        }
        if(A[i]==a1){cout<<y<<' '<<x<<endl;break;}
    }
}