#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int num[1000];
    for(int i=1;i<=n*m;i++){
        cin>>num[i];
    }
    int rf=num[1];
    sort(num+1,num+n*m+1,cmp);
    int rp;
    for(int i=1;i<=n*m;i++){
        if(num[i]==rf) {
            rp=i;
            break;
        }
    }
    int cnt=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                a[j][i]=cnt;
                if(a[j][i]==rp){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;

            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                a[j][i]=cnt;
                if(a[j][i]==rp){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }
    }
    return 0;
}
