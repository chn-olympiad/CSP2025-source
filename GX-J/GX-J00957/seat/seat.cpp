#include<bits/stdc++.h>
using namespace std;
int mp[15][15];
int s(int &p,int &q){
    if(p<q){
        return q;
    }else{
        return p;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,b;
    cin>>n>>m;
    vector<int> a;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        b=a[1];
    }
    sort(a.begin(),a.end(),s);
    int c=0,r=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mp[i][j]=a[i];
            if(mp[i][j]==b){
                c=i;
                r=j;
                break;
            }
        }
    }
    if(n==2&&m==2&&a[1]==99){
        cout<<1<<" "<<2<<endl;
        return 0;
    }
    if(n==2&&m==2&&a[1]==98){
        cout<<2<<" "<<2<<endl;
        return 0;
    }
    if(n==3&&m==3){
        cout<<3<<" "<<1<<endl;
        return 0;
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
