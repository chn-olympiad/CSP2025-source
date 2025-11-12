#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.in","w",stdout);
    int n,m,score,place=1,c,r;//r,n:hang,c,m:lie
    cin>>n>>m;
    int a1;
    cin>>a1;
    for (int i=1;i<n*m;i++)
    {
        int p;
        cin>>p;
        if (p>a1){
            place+=1;
        }
    }
    c=place/n;
    if(place%n!=0){
        c+=1;
    }
    if (c%2!=0){
        r=place-c*(n-1);
    }
    else{
        r=(c-1)*n-place+n;
    }
    cout<<c<<" "<<r;
    return 0;
}
