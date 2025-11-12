#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
pair<int,int> a[N];
int n,m;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int x=0;
    for(int i=1;i<=n*m;i++){
        if(a[i].second==1){
            x=i;
            break;
        }
    }
    int xx=x/n+1;
    if(x%n==0) xx--;
    if(xx%2==0){
        int yy=x%n;
        if(x%n==0) yy=n;
        cout<<xx<<" "<<m-yy+1;
    }
    else{
        int yy=x%n;
        if(x%n==0) yy=n;
        cout<<xx<<" "<<yy;
    }
    return 0;
}
