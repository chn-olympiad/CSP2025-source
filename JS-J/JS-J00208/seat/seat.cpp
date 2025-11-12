#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    vector <int> v;
    int n,m;
    cin>>n>>m;v.push_back(0);
    for(int i=0;i<n*m;i++){
        int j;
        cin>>j;
        v.push_back(j);
    }
    int r1=v[1];int c,r;
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        if(r1==v[i]){
           int k=v.size()-i;
            int c1=(k-1)%(2*n);
           c=(k-1)/n+1;
           if(c1<n){
                r=(k-1)%n+1;
           }else{
                r=n-k%n+1;
           }
           break;
        }
    }
    printf("%d %d",c,r);
    return 0;
}
