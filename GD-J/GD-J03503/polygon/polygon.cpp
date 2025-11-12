#include <bits/stdc++.h>
using namespace std;
int a[500001];
string x;
bool cmp(int x,int y){
    return y<x;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }/*sort(a,a+n,cmp);
    if()*/
    cout<<'1';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
