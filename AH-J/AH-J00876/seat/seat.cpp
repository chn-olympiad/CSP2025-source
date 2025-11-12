#include<bits/stdc++.h>
using namespace std;
const int D=10*10+5;
int a[D];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+1+s,greater<int>());
    int k=0;
    for(int j=1;j<=m;j++){
        if(j&1){
            for(int i=1;i<=n;i++){
                if(a[++k]==x){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
        }
        else{
            for(int i=n;i>=1;i--){
                if(a[++k]==x){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
        }
    }
}
