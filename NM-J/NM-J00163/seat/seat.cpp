#include<bits/stdc++.h>
using namespace std;
int a,b,c,d[100],f;
int n;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    n=a+b;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
    }
    int e=d[1];
    sort(d,d+n+1);

    for(int i=n;i>=1;i--)
    {

        if(e==d[i]){
            f=i;
        }

    }
    if(n-f==3)
    {
        cout<<a<<" "<<b;
    }
    else if(n-f==2)
    {
        cout<<a<<" "<<b-1;
    }
    else if(n-f==1)
    {
        cout<<a-1<<" "<<b;
    }
    else if(n-f==1)
    {
        cout<<a-1<<" "<<b-1;
    }
    return 0;
}
