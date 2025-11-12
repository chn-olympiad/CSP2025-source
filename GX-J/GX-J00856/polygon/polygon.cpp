#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m,R;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    int ns=1,ms=1,s=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++,s++){
            if(a[s]==R) {
                cout<<ms<<' '<<ns;
                return 0;
            }
            if(ms%2==0) ns--;
            else ns++;
        }
        ms++;
        if(ms%2==0) ns--;
        else ns++;
    }
}

