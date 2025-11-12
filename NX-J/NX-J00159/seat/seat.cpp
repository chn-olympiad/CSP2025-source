#include<bits/stdc++.h>using namespace std;

int main(){
    freopen ("seat.in","w",seat.in);
    freopen("seat.out","r".seat.out);
    int a[10000000],n,m,b=0,h=0,l=0;
    cin>>n>>M;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n*m;i++)
    {
    if(a[0<a[i]])
        b++;
    }
    l=b/m+1
    if(l%2==0)
    {
        h= n-(b-2*m);
    }
    else{
    h=b-2*m;
    }

    cout<<l<<" "<<h;

}

