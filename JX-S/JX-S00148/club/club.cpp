#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int t,n;
int a1,a2,a3;
long long b[6];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        long long a[N],ans=0;
        for(int j=1;j<=n;j++){
            cin>>a1>>a2>>a3;
            a[j]=a1;
        }
        sort(a+1,a+n+1,cmp);
        for(int j=1;j<=n/2;j++) ans+=a[j];
        b[i]=ans;
    }
    for(int i=1;i<=t;i++) cout<<b[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
