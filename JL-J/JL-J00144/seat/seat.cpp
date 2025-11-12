#include<bits/stdc++.h>
using namespace std;
int a[1000];
int mp[111][111];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int k=1,r=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[k++];
            if(k==2)r=a[1];
        }
    }
    sort(a+1,a+1+n*m,cmp);
    int k1=1;
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                if(a[k1++]==r){
                    cout << i << " " << j;
                return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                if(a[k1++]==r){
                    cout << i << " " << j;
                return 0;
                }
            }
        }

    }
    return 0;
}
