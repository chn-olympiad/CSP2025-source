#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("seat.in",r,stdin);
    //freopen("seat.out",w,stdout);
    int n,m,c,r,b,x,s,y,sum,jf;
    int a[100000];
    cin>>n;
    cin>>m;
    b=n*m;
    for(long long  i=1;i<=b;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a,a+b+1);
    for(int j=b;j>=1;j--){
        sum=sum+1;
        if(a[j]==x){
            if(sum<n||sum==n){
                c=1;
            }
            else if(sum>n){
                c=sum%n+(sum-n);
            }
            if(c%2==0){
                jf=sum-c*n;
                r=n-jf-1;
            }
            else if(c%2!=0){
                r=sum;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
