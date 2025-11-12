#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int q[9]={1,2,3,4,5,6,7,8,9};
    int b=0,c[10000],s=0;
    cin>>a;
    for(int i=1;i<=100000;i++){
    b++;
    if(a[i]==0){break;}
    }
    for(int i=0;i<=b;i++){
    sqrt((int)a[i]);
    }
    for(int i=0;i<=b;i++){
    for(int i=0;i<=b;i++){
    if(a[i]<a[i+1]){swap(a[i],a[i+1]);}
    }
    }
    for(int i=0;i<=b;i++){
    cout<<a[i];
    }
    return 0;
}

