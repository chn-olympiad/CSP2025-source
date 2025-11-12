#include<bits/stdc++.h>
using namespace std;
int n,m,b,k=1,d,p=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    b=n*m;
    int a[b+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            d=a[i];
        }
    }
    sort(a,a+b);
    if(a[1] == d)
    {
        cout<<1<<' '<<1;
    }
    for(int i=m;i>=1;i--){
        if(i%2==1){
            for(int j=n;j>=1;j--){
                if(a[k]==d){
                    cout<<i<<" "<<j;
                    p++;
                    break;
                }else{
                    k++;
                }
            }
        }
        if(p){
            break;
        }
        if(i%2==0){
            for(int l=1;l<=n;l++){
                if(a[k]==d){
                    cout<<i<<" "<<l;
                    break;
                }else{
                    k++;
                }
            }
        }
        k++;
    }
    fclose(stdin);
    fclose(stdout);
  return 0;
}
