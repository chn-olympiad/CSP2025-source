#include<bits/stdc++.h>
using namespace std;
int n,m;
string x,y,z;
struct node{
    string x,y;
}a[200100];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=m;i++){
        int cnt=0;
        cin>>x>>y;
        for(int j=1;j<=n;j++){
            int k=x.find(a[j].x),l;
            l=k;
            z=x;
            if(k<x.length()){
                for(;k<=k+a[j].x.length()-1;k++){
                    z[k]=a[j].y[k-l];
                }
                if(z==y){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
