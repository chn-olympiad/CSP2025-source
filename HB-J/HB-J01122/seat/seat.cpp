#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s=0;
    cin>>n>>m;
    int h=n*m;
    int a[n*m];
    for(int i=0;i<h;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<h;i++)
    {
        if(a[0]<a[i])
            s++;
    }
    int u,o;
    u=s/n;
    o=s%n;
    if(u%2==0)
        cout<<u+1<<" "<<o+1;
    else
        cout<<u+1<<" "<<n-o;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
