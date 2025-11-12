#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,inf=0x3f3f3f3f;
typedef long long ll;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==3){
        sort(a+1,a+1+n);
        if(a[1]+a[2]>a[3])cout<<a[3];
    }
    return 0;
}
/*
08:57 T1  100pts
09:32 T2  100pts
10:57 T3 5~40pts
11:32 T4   12pts
score:205pts~240pts
luogu:jiangzhexun
School:Five Elephants NO.14 junior high
Class:Class 57 Grand 7
