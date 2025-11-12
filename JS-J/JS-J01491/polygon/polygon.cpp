#include <bits/stdc++.h>
using namespace std;

int arr[5005];
bool cmp(int x,int y){
    return x>y;
}
// int fx(int l,int n,int m){
    

// }


int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n,cmp);
    if(n==3){                                            //point 12
        if(arr[1]+arr[2]>arr[0])
            cout<<1;
        else cout<<0;
        return 0;
    }
    
    // for(int i=3;i<=n;i++){
    //     fx(0,n,3);
    // }
    

    return 0;
}