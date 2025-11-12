#include<bits/stdc++.h>
using namespace std;
long long ans[100010];
int sum;
struct myd{
    int b1,b2,b3;
}a[1000100];
void mydh(int d,int my,int c1,int c2,int c3,int n){
    if(c1>n/2||c2>n/2||c3>n/2) return;
    if(d-1==n){
        sum=max(sum,my);
        return;
    }
    c1++;
    mydh(d+1,my+a[d].b1,c1,c2,c3,n);
    c1--;
    c2++;
    mydh(d+1,my+a[d].b2,c1,c2,c3,n);
    c2--;
    c3++;
    mydh(d+1,my+a[d].b3,c1,c2,c3,n);
    c3--;
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,n;
    cin>>t;
    for(int i=1;i<=t;i++){
        sum=0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j].b1>>a[j].b2>>a[j].b3;
        }
        if(n!=2)
            mydh(0,0,0,0,0,n);
        else
            sum=max(a[0].b1+a[1].b2,a[0].b1+a[1].b2);
            sum=max(sum,a[0].b2+a[1].b1);
            sum=max(sum,a[0].b2+a[1].b3);
            sum=max(sum,a[0].b3+a[1].b1);
            sum=max(sum,a[0].b3+a[1].b2);
        ans[i]=sum;
    }
    for(int i=1;i<=t;i++){
        cout<<ans[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

