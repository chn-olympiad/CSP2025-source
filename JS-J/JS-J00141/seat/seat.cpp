#include<bits/stdc++.h>
using namespace std;

const int maxn=110;
int a[maxn];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    int tot=n*m;
    for(int i=1;i<=tot;i++){
        cin>>a[i];
    }
    int tar=a[1];

    sort(a+1,a+tot+1);
    int idx=1;
    for(int i=1;i<=tot;i++){
        if(a[i]==tar){
            idx=tot-i+1;
            break;
        }
    }

    int n1=idx/n;
    int m1=idx%n;

    if(m1!=0) {
        n1++;
    }
    else{
        m1=n;
    }

    if(n1%2==0){
        cout<<n1<<" "<<n-m1+1;
    }
    else{
        cout<<n1<<" "<<m1;
    }
    return 0;
}
