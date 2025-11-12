#include<bits/stdc++.h>
using namespace std;
const int MAX_N=555555;
int n,k,SUM=0;
int a[MAX_N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k<=1){
        int sum=0;
    for(int i=0;i<n;i++){
        sum=(sum^a[i]);
        if(sum==k){
        SUM++;
        sum=0;
        continue;
        }
        if(a[i]==k){
        SUM++;
        sum=0;
        continue;
        }
    }
    cout<<SUM;
    return 0;
    }else{
    int sum=0;
    for(int i=0;i<n;i++){
        if(a[i]==k)SUM++;
    }

        for(int i=0;i<n-1;i++){

            for(int j=i+1;j<n;j++){
                    sum=0;
                    for(int kk=i;kk<=j;kk++){
                        sum=(sum^a[kk]);
                        if(a[kk]==k){
                            sum=0;
                            i=j+1;
                            break;
                        }
                    }
                if(sum==k){
                SUM++;
                i=j+1;
            }
            }

        }
    cout<<SUM;
    }

    return 0;
}
