#include<bits/stdc++.h>
using namespace std;
const int N=150;
int a[N];
int l=1;
int k=1;
int n,m;
int cnt=0;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int len=n*m;
    for(int i=1;i<=len;i++){
        cin>>a[i];
    }
    cnt=a[1];
    sort(a+1,a+1+len,cmp);
    for(int i=1;i<=m;i++){
        if(l==1){
            l=0;
            for(int j=1;j<=n;j++){
                if(a[k++]==cnt){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            l=1;
            for(int j=n;j>=1;j--){
                if(a[k++]==cnt){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}

