#include<bits/stdc++.h>
using namespace std;
int l[5001];
bool polygon(){
    int sum=0;
    for(int i=0;i<l.size();i++){
        sum+=l[i];
    }
    if(sum>l.max()*2){
        return 1;
    }
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m=3,a[5001],y,z;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(m<=n){
        for(int i=0)
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
