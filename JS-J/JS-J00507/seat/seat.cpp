#include<bits/stdc++.h>
using namespace std;
int a[109];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+k+1,greater<int>());
    int fl;
    for(int i=1;i<=k;i++){
        if(a[i]==s){
            fl=i;
            break;
        }
    }
//    cout<<fl<<' ';
    int t;
    if(fl%n==0) t=fl/n;
    else t=fl/n+1;
    cout<<t<<' ';
    int w;
    int ry=fl%n;
    if(ry==0) ry=n;
    if(t%2==1) w=ry;
    else w=n-(ry)+1;
    cout<<w;
    return 0;
}
