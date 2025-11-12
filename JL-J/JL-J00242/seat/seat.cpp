#include<bits/stdc++.h>
using namespace std;
void sor(int n,int a[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=1;
    cin>>n>>m;
    int a[n*m],a1,k=1,n1=1,m1=1;
    cin>>a1;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    sor(n*m,a);
    while(a[k]>a1){
        k++;
        cnt++;
    }
    for(int i=1;i<cnt;i++){
        if(n1%2==0){
            if(m1==1){
                n1++;
            }
            else{
                m1--;
            }
        }
        else{
            if(m1==n){
                n1++;
            }
            else{
                m1++;
            }
        }
    }
    cout<<n1<<" "<<m1;
    return 0;
}
