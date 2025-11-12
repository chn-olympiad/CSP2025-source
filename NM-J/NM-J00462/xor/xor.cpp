#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int s=0;
    int l=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int b=0;
    for(int i=0;i<n;i++)
    {
        b=b^a[i];
        if(b==k)
        {
            s++;
            b=0;
            l=i+1;
        }
        if(b!=0&&i==n-1)
            i=l+1;
    }
    cout<<s<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
