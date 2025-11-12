#include<bits/stdc++.h>
using namespace std;
int b[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int x;
    cin>>a;
    for(int i=1;i<=a.size();i++){
        if(a[i]-'0'>=0 && a[i]-'0'<=9){
            x=a[i];
            b[x]++;
            }
    }
    x=9;
    for(int i=x;i>=1;i--){
        if(b[x]==0)
            break;
        else
            while(b[x]--,x==0)
                cout<<x;
        x--;
    }
    return 0;
}
