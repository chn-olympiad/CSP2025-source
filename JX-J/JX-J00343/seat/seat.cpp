#include<bits/stdc++.h>
using namespace std;
int arr1[15][15],hang,lie,l,h,a,k,arr[110],n;
bool f=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>hang>>lie;
    for(int i=1;i<=hang*lie;i++){
        cin>>arr[i];
    }
    a=arr[1];
    sort(arr+1,arr+hang*lie+1,cmp);
    for(int i=1;i<=hang*lie;i++){
        if(arr[i]==a){
            k=i;
            break;
        }
    }
    //for(int i=1;i<=hang*lie;i++) cout<<arr[i]<<" ";
    for(int i=1;i<=lie;i++){
        if(i%2){
            for(int j=1;j<=hang;j++){
                n++;
                arr1[i][j]=arr[n];
                if(n==k){
                    f=1;
                    l=i;
                    h=j;
                    break;
                }
            }
        }
        else{
            for(int j=hang;j>=1;j--){
                n++;
                arr1[i][j]=arr[n];
                if(n==k){
                    f=1;
                    l=i;
                    h=j;
                    break;
                }
            }
        }
        if(f==1) break;
    }
    //cout<<arr1[l][h]<<endl;
    cout<<l<<" "<<h;
    return 0;
}
