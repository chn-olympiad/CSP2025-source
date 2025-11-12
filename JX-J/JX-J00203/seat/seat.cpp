#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[101];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int mark=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==mark){
            x=ceil(i*1.0/n);
            if(x%2==1){
                cout<<x<<" "<<i-(x-1)*n;
                return 0;
            }
            else{
                cout<<x<<" "<<x*n+1-i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
