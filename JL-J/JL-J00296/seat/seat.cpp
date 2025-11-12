#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(i==0){
            b=a[i];
        }
    }
    sort(a,a+n*m,cmp);
    int d;
    for(int i=0;i<n*m;i++){
        if(a[i]==b){
            d=i+1;
        }
    }
    int c=0;
    bool flag=0;
    for(int i=1;i<=m;i++){
        if(flag==0){
            flag=1;
        }
        else{
            flag=0;
        }
        if(flag==1){
            for(int j=1;j<=n;j++){
                c++;
                if(c==d){
                    cout<<i<<" "<<j;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                c++;
                if(c==d){
                    cout<<i<<" "<<j;
                }
            }
        }

    }
    return 0;
}

