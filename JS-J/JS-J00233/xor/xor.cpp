#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int a,n,k,count1;
    cin>>n>>k;
    count1=0;
    for(int i = 0;i<n;i++){
        cin>>a;
        if(a==1){
            count1++;
        }
    }
    if(k==0){
        cout <<(count1/2);
    }else{
        cout <<count1;
    }



    return 0;
}