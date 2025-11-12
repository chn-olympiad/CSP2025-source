#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[10001]={};
    cin>>n>>m;
    int c=n*m;
    for(int i=1;i<=c;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+c,cmp);
    int d = a[1];
    int f;
    for(int i=1;i<=c;i++){
        if(d == a[i]){
            f = i;
        }
    }
    if(n % 2 == 0){
        cout<<(f+1)<<" "<<(f+1);
    }else{
    cout<<(f+1)+1<<" "<<(f+1)-1;
    }

}
