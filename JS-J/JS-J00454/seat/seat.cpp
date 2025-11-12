#include<bits/stdc++.h>
using namespace std;
int m,n,num[10005];
int ga,s;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>m;

    for(int i=0;i<m*n;i++){
       cin>>num[i];
    }
    ga=num[0];
    int k=m*n;
    sort(num,num+k,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(num[s]==ga){
                if(i%2==0){
                    cout<<i<<" "<<n-j+1;
                }
                else{
                    cout<<i<<" "<<j;
                }
                return 0;
            }
            s++;
        }
    }
}
