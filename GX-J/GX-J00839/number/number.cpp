#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    char b[10000];
    int c=0;
    int sum=0;
    int max1=0;
    cin>>a;
    for(int i=0;i<=a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[i]=a[i];
        }
    }
    sort(b,b+a.size());
    for(int i=a.size();i>=0;i--){
            cout<<b[i];
        }

    return 0;
}
