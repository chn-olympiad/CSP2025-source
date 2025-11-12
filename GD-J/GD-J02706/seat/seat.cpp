/*
听好了，出体人。
等我AKIOI，我会制定新的考场规则。
题目难度不按主观升序要扣税
出大模拟要扣税
卡常数更要扣税
构造题不给大样例要扣税
大样例用脚造要扣税
出超纲题要扣税 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=107;
long long n,m,i,j,k,a[N],ans;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n*m;i++) cin>>a[i];
    for(i=1;i<n*m;i++) if(a[i]>a[0]) ans++;
    cout<<ans/m+1<<" "<<((ans/m)%2==0?(ans%m)+1:-((ans%m)-m));
    return 0;
}
