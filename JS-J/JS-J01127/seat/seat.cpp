#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n*m+1);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int t=a[1];
    int x=0,y=0;
    sort(a.begin()+1,a.end(),greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            y=i/m;
            if(i%m!=0){
                y++;
            }
            if(y%2==1){
                x=n-(y*n-i);
            }else{
                x=y*n-i+1;
            }
            break;
        }
    }
    cout<<y<<' '<<x<<'\n';
    return 0;
}
