#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int chu(int a,int b){
    if(a==b){
        return a/b;
    }else{
        return a/b+1;
    }
}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    const int x=n*m;
    for(int i=0;i<x;i++){
        cin>>a[i];
    }
    int my=a[0];
    int pai=0;
    sort(a,a+x,cmp);
    for(int i=0;i<x;i++){
        if(a[i]==my){
            pai=i+1;
            break;
        }
    }
    int a1=chu(pai,n);
    int a2;
    if(a1%2==0){
        int tp=n*(a1-1)+1;
        for(int i=n;i>0;i++){
            if(tp==pai){
                a2=i;
                break;
            }
            tp++;
        }
    }else{
        int tp=n*(a1-1)+1;
        for(int i=1;i<=n;i++){
            if(tp==pai){
                a2=i;
                break;
            }
            tp++;
        }
    }
    cout<<a1<<' '<<a2;
    return 0;
}