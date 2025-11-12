#include<bits/stdc++.h>
using namespace std;
int n,m,c,n1=1,m1=0;
int a[100];
int a1[100];
int b[10][10];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    a1[1]=1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n*m-1;i++){
        for(int j=n*m-1;j>=i;j--){
            if(a[j]<=a[j+1]){
                swap(a[j],a[j+1]);
                swap(a1[j],a1[j+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a1[i]==1){
            c=i;
        }
    }
    for(int i=1;i<=c;i++){
        if(n1%2==1){
            if(m1==m){
                n1++;
            }else{
                m1++;
            }

        }else if(n1%2==0){
            if(m1==1){
                n1++;
            }else{
                m1--;
            }

        }

    }
    cout<<n1<<" "<<m1;
    return 0;
}
