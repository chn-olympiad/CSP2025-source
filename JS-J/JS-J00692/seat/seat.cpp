#include<bits/stdc++.h>
using namespace std;
int n,m,x,sum,num;
vector<int>a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    a.push_back(x);
    sum=x;
    for(int i=2;i<=n*m;i++){
        cin>>x;
        a.push_back(x);
    }
    reverse(a.begin(),a.end());
    for(int i=1;i<=m;i++){
        if(m%2==1){
            for(int j=1;j<=n;j++){
                num++;
                if(a[num]==sum){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                num++;
                if(a[num]==sum){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}