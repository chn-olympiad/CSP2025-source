#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[105],b[15][15];
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)scanf("%d",&a[i]);
    k=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0,l=0;i<n;i++){
        for(int j=0;j<m;j++,l++)b[j][i]=a[l];
        i++;
        if(i!=n)for(int j=m-1;j>=0;j--,l++)b[j][i]=a[l];
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(b[i][j]==k){
        cout<<j+1<<' '<<i+1;
        return 0;
    }
    return 0;
}
