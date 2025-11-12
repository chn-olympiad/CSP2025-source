#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,m,a[110],q=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int A=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m-i;j++){
            if(a[j]<a[j+1])
                swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==A) q=i;
    }
    for(int i=1;i<=m;i++){
        int e=0,j=1;
        while(j<m && i%2!=0){
            j++;e++;
        }
        while(j<=m && i%2==0 && j>=1){
            j--;e++;
        }
        if(e==q){
            printf("%d%d",j,i);
            break;
        }
    }
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    return 0;
}
