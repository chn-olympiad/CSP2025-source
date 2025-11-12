#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],b[101];
long long ans,ams;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    ans=n*m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+1+ans,cmp);
    for(int i=1;i<=ans;i++){
        if(a[i]==b[1]){
            if(i%n!=0&&((i/n)+1)%2==1){
                cout<<i/n+1<<" "<<i%n;
                break;
            }
            if(i%n==0&&(i/n)%2==1){
                cout<<i/n<<" "<<n;
                break;
            }
            if(i%n!=0&&((i/n)+1)%2!=1){
                    if(i%n!=1){
                         cout<<i/n+1<<" "<<n-(i%n);
                         break;
                    }
                    else{
                        cout<<i/n+1<<" "<<n;
                        break;
                    }

            }
            if(i%n==0&&(i/n)%2!=1){
                cout<<i/n<<" "<<1;
                break;
            }
        }
    }
    return 0;
}
