#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,num=0;
    int one_num=0,zero_num=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    if(k==0){
        for(int i=0;i<n;i++){
            if(a[i]==0) zero_num++;
            if(a[i]==1) one_num++;
            if(zero_num!=one_num){
                num++;
                zero_num=0;
                one_num=0;
            }
        }
    }else if(k==1){
        for(int i=0;i<n;i++){
            if(a[i]==0) zero_num++;
            if(a[i]==1) one_num++;
            if(zero_num==one_num){
                num++;
                zero_num=0;
                one_num=0;
            }
        }
    }else{
        cout<<0;
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
