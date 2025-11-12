#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a;
signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,miNe=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        int b;
        cin>>b;
        if(i==1)miNe=b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    int seAt;
    for(int i=0;i<=a.size()-1;i++){
        if(a[i]==miNe){
            seAt=i;
        }
    }
    seAt++;
    seAt=(n*m)-seAt+1;
    int l=seAt/n,h=seAt%n;
    if(seAt%n!=0){
        l++;
    }else h=n;
    if(l%2==0)h=n-h+1;
    cout<<l<<" "<<h;
    return 0;
}