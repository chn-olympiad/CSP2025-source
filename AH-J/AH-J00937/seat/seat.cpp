#include<bits/stdc++.h>
using namespace std;
int i,n,m,a[150],x=1,y=1,b,f;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=a[1];cout<<a[1];
    sort(a+1,a+n*m+1);
    for(i=n*m;i>=1;i--){
        if(a[i]==b)f=n*m-i;
    }
    for(i=1;i<=f;i++){
        if(x%2==1&&y==n){
			x++;
		}else if(x%2==0&&y==1){
			x++;
		}else if(x%2==1&&y!=n){
			y++;
		}else{
			y--;
		}
    }
    cout<<x<<" "<<y;
    return 0;
}
