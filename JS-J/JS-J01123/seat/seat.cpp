#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,k=0,hang=0,lie=0,grade=0,pos=0;
int a[110];
bool cmp(int k1,int k2)
{
    if(k1>k2) return true;
    return false;
}
int main()
{
    freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=k;i++) cin>>a[i];
    grade=a[1];
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++){
        if(a[i]==grade) pos=i;
    }
    if(pos%n!=0) lie=pos/n+1;
    else lie=pos/n;

    if(lie%2==0){
        hang=n-pos%n+1;
        if(pos%n==0) hang-=n;
    }
    else{
        hang=pos%n;
        if(pos%n==0) hang+=n;
    }
    cout<<lie<<' '<<hang<<"\n";

    //cout<<pos<<' '<<lie<<"\n";
    //for(int i=1;i<=n*m;i++) cout<<a[i]<<' ';
    return 0;
}
/*
2 3
20 14 30 21 18 16

5 3
44 91 1 9 6 78 67 20 10 40 37 36 31 29 43
*/
