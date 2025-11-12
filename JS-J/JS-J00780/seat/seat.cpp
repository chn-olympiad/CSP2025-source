#include<bits/stdc++.h>
using namespace std;
long long int n,m;
bool cmp(long long int x,long long int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long int t=n*m;
    long long int a[t+1];
    for(long long int i=1;i<=t;i++){
        cin>>a[i];
    }
    long long int t2=a[1];
    sort(a+1,a+1+t,cmp);
    long long int t1=1;
    long long int b;
    for(long long int i=1;i<=t;i++){
        if(a[i]==t2){
            b=i;
        }
    }
    for(long long int i=1;i<=m;i++){
        if(i%2==0){
            for(long long int j=n;j>=1;j--){
                if(b==1){
                    cout<<i<<" "<<j;
                    return 0;
                }
                b--;
            }
        }else{
            for(long long int j=1;j<=n;j++){
                if(b==1){
                    cout<<i<<" "<<j;
                    return 0;
                }
                b--;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
}
