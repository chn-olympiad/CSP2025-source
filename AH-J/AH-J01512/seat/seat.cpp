#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2+10;
int n,m,a[N],goal,k,cnt,x,y;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cnt=n*m;
    for(int i=1;i<=cnt;i++){//O(n) 1e2
        cin>>a[i];
    }goal=a[1];
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){//O(n) 1e2
        if(a[i]==goal){
            k=i;
            break;
        }
    }
    if(k%n==0){//O(1)
        x=k/n;
        if(x%2==0){
            y=1;
        }else{
            y=n;
        }
    }else{
        x=k/n+1;
        if(x%2==0){
            y=n-k%n+1;
        }else{
            y=k%n;
        }
    }
    cout<<x<<' '<<y;
    return 0;
}
