#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int MAX_a=-1;
bool v[1000005];
int ans=0;
int sum;
bool MAX(int s)
{
    if(s>MAX_a)return false;
    return true;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        MAX_a=max(MAX_a,a[i]);
    }
    for(int l=1;l<=n;l++){
        for(int j=1;j<=n-l;j++){
            for(int k=1;k<=l-j;k++)
                sum=a[l]+a[j]+a[k];
                if(MAX(sum)==true)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/
