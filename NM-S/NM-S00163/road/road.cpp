#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int flag=true;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int maxn;
    int n,k,m,b;
    cin>>n>>k>>m;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(flag==true)
            {
                cnt++;

            }
        }

    }

    maxn=max(maxn,b);
    cout<<maxn;
    return 0;
}
