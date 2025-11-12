#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;cin>>n>>m;
    int ans;cin>>ans;
    vector<int> a(n*m);a[1]=ans;
    for(int i=1;i<n*m;i++) cin>>a[i+1];
    sort(a.begin()+1,a.begin()+1+n*m,greater<int>());

    bool down=1;int r=1;int c=1;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==ans)
        {
            cout<<r<<" "<<c<<"\n";
            break;
        }
        if(down) c++;
        else c--;
        if(c>n)
        {
            //cout<<"bottem\n";
            down=0;
            c=n;
            r++;
        }
        if(c<1)
        {
            //cout<<"top\n";
            down=1;
            c=1;
            r++;
        }
        //cout<<i<<": "<<r<<" "<<c<<"\n";
    }
    return 0;
}