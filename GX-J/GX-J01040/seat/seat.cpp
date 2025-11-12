
#include <bits/stdc++.h>

using namespace std;
int B[10001];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);


    int n,m;
    cin>>n>>m;
    int p;
    for(int i=1;i<=n*m;i++){
        cin>>B[i];
        if(i==1){
            p=B[i];
        }

    }
    for(int i=1;i<=n*m;i++){
        for(int i1=i+1;i1<=n*m;i1++){
            if(B[i1]>B[i]){
                swap(B[i1],B[i]);
            }
        }
    }
    int k;

    for(int i=1;i<=n*m;i++){

       if(p==B[i]){
            k=i;
            break;
       }
    }
    int h,l;

        l=k/n;
        if(k%n!=0){
            l++;
        }
        if(l%2==0){
            cout<<l<<" "<<n-k%n+1;
        }else{
            cout<<l<<" ";
            if(k%n==0){
                cout<<n;
            }else{
                cout<<k%n;
            }

        }


   /* int o=0;
    for(int i=0;i<m;m++){
        int p=n-1;
        for(int j=0;j<n;j++){
            if(i%2==0){
                A[j][i]=B[o];

            }else{
                A[p-j][i]=B[o];
            }
            o++;
        }
    }*/


    return 0;
}
