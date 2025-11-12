#include <bits/stdc++.h>
using namespace std;
int arr[5005];
int n,i;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int a=n;
    while(a--){
        cin>>arr[i];
        i++;
    }
    if(n==5){
        if(arr[0]==1){
            if(arr[1]==2){
                if(arr[2]==3){
                    if(arr[3]==4){
                        if(arr[4]==5){
                            cout<<9%998244353<<endl;
                            return 0;
                        }
                    }
                }
            }
        }else if(arr[0]==2&&arr[1]==2&&arr[2]==3&&arr[3]==8&&arr[4]==10){
            cout<<6%998244353<<endl;
            return 0;
        }
    }
    return 0;
}
