#include <bits/stdc++.h>

using namespace std;
int n,m;
int x,y;
int num=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    for(int i=2;i<=n*m;i++){
        cin>>y;
        if(y>x)num++;
    }
    cout<<num/m<<" ";
    if(num%n==0)cout<<n;
    else cout<<num%n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
