#include<bits/stdc++.h>
using namespace std;
int m,n,a[110],r,j=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a,a+n*m+1);
    for(int i=m*n;i>=1;i--){
		j=n*m-i;
        if(a[i]==r){
            if(j<n){
                cout<<1<<" "<<j;
                return 0;
            }
            if(j/n==0){
                 cout<<(j+1)/n<<" "<<1;
                 return 0;
			}
			else cout<<j/n+1<<" ";
			
            if((j/n)%2==0)cout<<j%n+1;
            else cout<<n-j%n;
        }
    }
    return 0;
}