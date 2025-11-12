#include <bits/stdc++.h>

using namespace std;
int s[12][12],a[1004],ma[1004];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    memset(ma,-1,sizeof(ma));
    int n,m;
    scanf("%d%d",&n,&m);
    int nm=n*m;
    for(int i=1;i<=nm;i++){
        scanf("%d",&a[i]);
    }
    int x=a[1]; // xiaoR's seat
    //    reverse(a,a+n*m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==x){
                cout << j << " " << i;
                return 0;
            }
        }
    }
    return 0;
}
