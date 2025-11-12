#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a1,a[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
    }
    a1=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;++i){
        if(a[i]==a1){
            int x,y;
            x=(i+n-1)/n;
            y=i%n;
            if(x%2==0){
                if(y==0) y=1;
                y=n-y+1;
            }else if(y==0){
                y=n;
            }
            cout<<x<<' '<<y;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
