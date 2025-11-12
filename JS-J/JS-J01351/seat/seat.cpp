#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
int n,m,a[11451],x;

int cmp(const int a,const int b){
    return a>b;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(x==a[i]){
            cout<<"xiao ming's location is "<<i<<"\n";
            int lie=ceil(i*1.0/n);
            int hang=i-(lie-1)*n;
            if(lie%2==0){
                hang=n-hang+1;
            }
            cout<<lie<<" "<<hang<<endl;
        }
    }
    return 0;
}
