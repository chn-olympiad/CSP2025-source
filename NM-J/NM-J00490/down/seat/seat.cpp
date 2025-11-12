#include<bits/stdc++.h>
using namespace std;
const int max = 110;
int a[maxn][maxn];
bool cmp(int a,int b){
    return a > b;
}
int mian(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>v;
    int n,m;
    cin>>n>>m;
    int l = n,m;
    for(int i =1;i<= l;i++){
        cin>>v[i];
        if(i == 1) s = v[i];
    }
    sort(v.begin(),v.end(),cmp);l
    int a = 0;
    for(int i = 1;i <= l;i++){
        if(v[i] == s) a = i;
    }
    if(a <= n) {
        cout<<1<<" "<<a;
    }else{
        while(1){

        }
}
