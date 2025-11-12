#include <bits/stdc++.h>
using namespace std;

int a[10000];
int main(){
    freopen("polygon.in","r",std);
    freopen("polygon.out","w",std);
    int n;
    cin>>n;
    int b=3,s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m=0,s=0,sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>m)
            m=a[i];
        sum+=a[i]
    }
    if(a[i]>2*m)
        s++;
    cout<<s<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
