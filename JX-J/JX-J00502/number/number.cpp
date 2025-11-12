#include <bits/stdc++.h>
using namespace std;
char a[100007],b[100007];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n;i++){
        a[i]=s[i];
    }
    for (int i=0;i<n;i++){
        if (a[i]>=48 && a[i]<=57){
            b[i]=a[i];
        }
    }
    sort(b,b+n,cmp);
    for (int i=0;i<n;i++){
        cout<<b[i];
    }
    return 0;
}
