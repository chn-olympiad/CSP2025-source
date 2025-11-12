#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    string a;
    getline(cin,a);
    int n,m,xm=a[0],w;
    int hang,lie;
    cin>>n>>m;
    for(int i=0;i<a.size();i++){
        if(a[i]<=a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]==xm){
            w=i;
        }
    }
    for(int i=w;i>=0;i-=n){
            lie++;
        if(i-n<=0){
            hang=i;
        }
    }
    cout<<lie<<" "<<hang;
    return 0;
}
