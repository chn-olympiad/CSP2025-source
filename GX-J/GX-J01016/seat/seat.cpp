#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a[100005],x;
vector <int> v;
vector <int> v2;
int main(){
    cin>>n>>m>>a1;
    a[0]=a1;
    for(int i=2;i<=m*n-1;i++){
        cin>>a[i-1];}
    sort(a,a+n*m+1);
    for(int j=1;j<=n*m;j++){
        if(a[j-1]==a1){
            x=j-1;
            break;}
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            v.push_back(i);}}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            v2.push_back(i);}}
    cout<<v2[x]-1<<" "<<v[x];
    return 0;
    }
