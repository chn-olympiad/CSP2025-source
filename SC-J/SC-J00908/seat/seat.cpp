#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    vector<int>A(n*m);
    int a;
    for(int i=0;i<n*m;i++)
    {
        cin>>A[i];
        if(i==0) a=A[i];
    }
    sort(A.begin(),A.end());
    for(int i=A.size()-1;i>=0;i--)
    {
        if(a==A[i])
        {
            int p=(n*m-i-1)/n;
            if(p%2==0)
            {
                cout<<p+1<<" "<<(n*m-i)-p*n;
                break;
            }
            else
            {
                cout<<p+1<<" "<<m-((n*m-i)-p*n)+1;
                break;
            }
        }
    }
    return 0;
}