#include<bits/stdc++.h>
using namespace std;
int a[105]={0};
int n,m;
int x;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    cin>>a[i];
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int num=(i-1)*m+j;
            if(a[num]==x){
                if(i%2==1)
                cout<<i<<" "<<j;
                else
                    cout<<i<<" "<<n-j+1;
                return 0;
            }
        }
    }
}
