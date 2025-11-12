#include <bits/stdc++.h>
using namespace std;
int c[1000005],n=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]-'0'>=0 && a[i]-'0'<=9){
            c[n]=a[i]-'0';
            n++;
        }
    }
    sort(c,c+n,cmp);
    for(int i=0;i<n;i++){
        cout<<c[i];
    }
    return 0;
}
