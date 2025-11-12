#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
int a[100010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int b=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(b==a[i]) sum=i;
    }
    if(sum<=n) cout<<"1"<<" "<<sum<<endl;
    else{
        for(int i=2;i<=m;i++){
            if(i%2==0){
                if(n*i-sum>=0){
                    cout<<i<<" "<<(n*i-sum+1)<<endl;
                    return 0;
                }
                else continue;
            }
            else{
                if(n*i-sum>=0){
                    cout<<i<<" "<<(n*i-sum)<<endl;
                    return 0;
                }
                else continue;
            }
        }
    }
    return 0;
}
