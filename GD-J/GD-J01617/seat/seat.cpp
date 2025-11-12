#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int>a[10005];
bool cmp(pair<int,int>x,pair<int,int>y){return x.first>y.first;}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+(n*m)+1,cmp);
//    for(int i=1;i<=n*m;i++)cout<<a[i].first<<" ";
//    cout<<endl;
//    for(int i=1;i<=n*m;i++)
//    {
//        cout<<(i-1)/n+1<<" ";
//        if((i-1)%(2*n)+1<=n)cout<<(i-1)%n+1;
//        else cout<<n-((i-1)%n);
//        cout<<endl;
//    }
//    cout<<endl;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].second==1)
        {
            cout<<(i-1)/n+1<<" ";
            if((i-1)%(2*n)+1<=n)cout<<(i-1)%n+1;
            else cout<<n-((i-1)%n);
            return 0;
        }
    }
    return 0;
}

/*

2 2
99 100 97 98

2 2
98 99 100 97

*/
