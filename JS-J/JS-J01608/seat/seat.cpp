#include<bits/stdc++.h>
using namespace std;
//const int MAXN=1000100;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int nums[140];
    cin>>n>>m;
    int a=n*m;
    for(int i=0;i<a;i++){
        cin>>nums[i];
    }
    int b=nums[0];
    sort(nums,nums+a,cmp);
    for(int i=0;i<a;i++){
        if(nums[i]==b){
            cout<<i/n+1<<' '<<(((i/n+1)%2==0)?n-(i%n):(i%n)+1);
        }
    }
    return 0;
}
//2 2 99 100 97 98
/*
100 8
99  88
98  90
*/
