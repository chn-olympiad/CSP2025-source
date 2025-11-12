#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat","w"stdin)
    freopen("seat","r"stdout)
    int n,m;
    cin>>n;
    cin>>m;
    int s[n*m];
    int r=0;
    int c=0;
    int x;
    x=n*m;
    int a[x];
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    for(int j=1;j<=x){
        if(a[j]>a[j+1]){
            c=1;
            r=1;
            else
                    c++;
                    r++;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
