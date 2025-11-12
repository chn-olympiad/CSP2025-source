#include<bits/stdc++.h>
using namespace std;

int n,m;
int k;
int a[105];

bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        if(i==1){
            cin>>k;
            a[1] = k;
        }else{
            cin>>a[i];
        }
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            k = i;
            break;
        }
    }
    cout<<(k-1)/n+1<<" ";
    if((k-1)/n%2==0){
        cout<<(k-1)%n+1;
    }else{
        int t = (k+m)%n+1;
        cout<<abs(m-t)+1;
    }
    return 0;
}
