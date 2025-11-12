#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[110],cnt,s,an,am;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;

    for(int i=1;i<=n*m;i++) cin >> a[i];
    s=a[1];

    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }

    for(int i=1;i<n*m;i++){
        if(s==a[i]){
            cnt=i;
            break;
        }
    }

    for(int i=1;i<=m;i++){
        if(cnt<=n*i){
            an=i;
            break;
        }
    }

    int n1=(an-1)*n+1;
    int n2=n1+n-1;

    for(int i=n1;i<=n2;i++){
        if(s==a[i]){
            if(an%2==1){
                if(i>n){
                    am=i%n;
                }else{

                    am=i;
                }
            }else{
                am=n-(i%n)+1;
            }
        }
    }
    cout << an << ' ' <<am;
    return 0;
}
