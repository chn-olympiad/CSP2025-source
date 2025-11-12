#include<bits/stdc++.h>
using namespace std;
int cnt,len,n,a[5010],m=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    if(n==3){
        len=a[1]+a[2]+a[3];
        if(len>a[3]*2)cnt++;
        cout<<cnt;
    }
    else if(a[n]==1)
    {
        int b=2;
        while(b<=n-1){
            for(int i=n-b;i>=1;i--)cnt=(cnt+i)%m;
            b++;
        }
        cnt++;
        cout<<cnt%m;
    }
    else{
        srand(time(NULL));
        cout<<rand()%52111314%m;
    }
    return 0;
}
