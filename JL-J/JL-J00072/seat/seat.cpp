#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
vector<int>v;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,x,an,am,cnt=0;
    cin>>n>>m;
    int l=0,r=m*n-1,mid;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            v.push_back(x);
        }
    }
    x=v[0];
    sort(v.begin(),v.end(),cmp);
    while(1){
        mid=(l+r+1)/2;
        if(v[mid]==x){
            break;
        }
        if(v[mid]>x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    mid++;
    am=(mid+n-1)/n;
    an=mid%n;
    if(!an){
        an=n;
    }
    if(!(am%2)){
        an=abs(m-an)+1;
    }
    cout<<am<<' '<<an;
    return 0;
}
