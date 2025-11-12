#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int cnt=0;
int b;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int c=a[0];
    sort(a,a+n*m);
    for(int i=n*m-1;i>=0;i--){
        if((n*m-1-i)%m==0){
            cnt++;
        }
        if(a[i]==c){
            b=n*m-i;
            if(b%n==0){
                b=n;
            }
            else{
                b=b%n;
            }
            if(cnt%2==0){
                cout<<cnt<<" "<<n+1-b;
            }
            else{
                cout<<cnt<<" "<<b;
            }
            return 0;
        }
    }
}
