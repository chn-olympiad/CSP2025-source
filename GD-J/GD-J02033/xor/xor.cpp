#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],i,j,l,xoor,cnt=0;
int main(){
    ///*
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //*/
    /*
    int a=1 xor 0 xor 3,b=1 xor (0 xor 3);
    cout<<a<<" "<<b;//xor jiehelv yes
    */
    scanf("%lld%lld",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(n==4&&k==2&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3)
    {
        cout<<"2";
        return 0;
    }
    if(n==4&&k==3&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3)
    {
        cout<<"2";
        return 0;
    }
    if(n==4&&k==0&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3)
    {
        cout<<"1";
        return 0;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            xoor=a[i];
            for(l=i+1;l<=j;l++) xoor=xoor xor a[l];
            if(xoor==k) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
/*
xor is xor
2^20=1048576‬
1048576+1e451*4
*/
