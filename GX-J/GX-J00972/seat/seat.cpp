#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[105][105];
bool cmp(int x,int y)
{
    return x<y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++)cin>>a[i];
    int r=a[1];
    sort(a+1,a+1+k,cmp);
    for(int i=1;i<=n;i++){
        if(i%2==1)
            for(int j=1;j<=m;j++){
                b[j][i]=a[k];
                if(a[k]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
                k--;
            }
        else if(i%2==0)
            for(int j=m;j>=1;j--){
                b[j][i]=a[k];
                if(a[k]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
                k--;
            }
    }
    return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
