#include<bits/stdc++.h>
using namespace std;

ifstream fin("seat.in");
ofstream fout("seat.out");
int n,m,p;
pair<int,int>a[1001];

int main()
{
    // freopen("seat.in","r",stdin);
    // freopen("seat.out","w",stdout);
    fin>>n>>m;
    for(int i=0;i<n*m;i++)
        fin>>a[i].first,
        a[i].second=i;
    sort(a,a+n*m);
    reverse(a,a+n*m);
    for(int i=0;i<n*m;i++)
        if(!a[i].second)
            p=i;
    fout<<p/n+1<<" "<<((p/n&1)?(n-p%n):(p%n+1))<<"\n";
}