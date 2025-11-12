#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int s=1,n[100005];
    cin>>a;
    for(int i=0;i<=a.length();i++){
        if(a[i]<='9'&&a[i]>='0'){
            n[s]=a[i];
            if(i!=a.length()-1){
                s++;
            }
        }
    }
    sort (n+1,n+s+1,cmp);
    for(int i=1;i<s;i++){
        cout<<n[i]-48;
    }
    return 0;
}
