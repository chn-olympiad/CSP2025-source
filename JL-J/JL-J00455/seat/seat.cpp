#include<bits/stdc++.h>
using namespace std;
int m,n,p,o;
vector<long long>v;
long long cmp(int a,int b){
    return a>b;
}
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m*n;i++){
        cin>>p;
        v.push_back(p);
        if(i==0){
            p=o;
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                if(v[j]==o){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=m;j>=1;j--){
                if(v[j]==o){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
