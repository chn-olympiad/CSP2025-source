#include<bits/stdc++.h>
using namespace std;

struct city_map{int a;int b;int use;};
struct country_map{int use[100000];};

int main(){
    freopen("road.in","r",stdin);
    freopen("rode.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    city_map c[m+1];
    country_map x[n+1];
    for(int i=0;i<m;i++){
        cin>>c[i].a>>c[i].b>>c[i].use;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>x[i].use[j];
        }
    }
    if(k==0&&(n==1||n==0))cout<<0;
    if(k==0&&n==2)cout<<c[0].use;
    bool swapped = false;
    for(int i=0;i<3-1;++i){
            for(int j=0;j<3-i-1;++j){
                if(c[j].use>c[j+1].use){
                    swap(c[j],c[j+1]);
                    swapped = true;
                }
            }
            if(!swapped)break;
        }
    if(k==0&&n==3){
    if(m==2)cout<<(c[0].use+c[1].use);
    if(m==3)cout<<(c[0].use+c[1].use);}
    return 0;
}
