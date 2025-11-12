#include <bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if (n==1 && m==1){
        cout<<"1 1";
        return 0;
    }
    int R=a[1];
    sort(a+1,a+n*m+1,cmp);
    int pos=-1;
    for (int i=1;i<=n*m;i++){
        if (a[i]==R){
            pos=i;
            break;
        }
    }
    int col=(pos+n-1)/n;
    cout<<col<<" ";
    if (col%2==1){
        int now=pos/(n+1);
        int num=pos-now*n;
        if (num<=n){
            cout<<num;
        }
        else{
            cout<<num%n;
        }
    }
    else{
        int nowcr=col*n;
        cout<<nowcr-pos+1;
    }
    return 0;
}
