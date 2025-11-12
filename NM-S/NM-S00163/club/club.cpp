#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int n[100];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n;
    int a,b,c;
    int maxn;
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n/2;i++)
    {
        for(int j=1;j<=3;j++)
        {


        if(n%2==0)
        {
            cout<<a<<" "<<b<<" "<<c<<" ";
        }
        }
    }
    maxn=max(maxn,n);
    cout<<maxn;
    cout<<endl;
    return 0;
}
