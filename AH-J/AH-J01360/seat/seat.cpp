#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x,id;
}a[101];
bool cmp(Node A,Node B){
    return A.x>B.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int N=n*m;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i].x;
        a[i].id=i;
    }
    sort(a+1,a+N+1,cmp);
    int Num;
    for(int i=1;i<=N;i++)
    {
        if(a[i].id==1)
        {
            Num=i;
            break;
        }
    }
    int c=(Num+n-1)/n,r;
    if(c%2==1)
    {
        r=Num%n;
        if(r==0)r=n;
    }
    else
    {
        if(Num%n==0)r=1;
        else r=n-(Num%n)+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
