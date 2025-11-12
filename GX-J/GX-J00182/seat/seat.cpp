#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[105];
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
    }

    int r=a[1];
    int num=0;
    int sy=1;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n;i++){
        if(n%2==0){
            sy=m;
            for(int j=sy;j>=1;j--){
                num++;
                if(a[num]==r){
                    cout << n << " " << m;
                }
            }
        }
        else{
            for(int j=sy;j<=m;j++){
                num++;
                if(a[num]==r){
                    cout << n << " " << m;
                }
            }
        }
    }
    return 0;
}
