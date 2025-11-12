#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
int f(int x,int y,int z,int t){
    long long s=0;
    if(t)s++;
    if(x==n)return s;
    for(int i=x;i<n;i++){
        if(y<2)s+=f(i+1,y+1,z+a[i],0);
        else if(z>a[i])s+=f(i+1,y+1,z+a[i],1);
        else s+=f(i+1,y+1,z+a[i],0);
        s%=998244353;
    }
    return s;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    cout<<f(0,0,0,0);
    return 0;
}
