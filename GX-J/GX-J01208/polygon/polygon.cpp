#include<bits/stdc++.h>
using namespace std;
int n,a[10005],x,y,b,zby=3;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    if(n<=3){
       for(int i=1;i<=n;i++){
            if(a[i]>=a[i-1]){
            b=a[i];
            }
            x+=a[i];
        }
        if(x>=b*2){
        cout<<1;
        }
    }
    else{
		for(int j=1;j<=n;j++){
            for(int i=1;i<=zby;i++){
            if(a[i]>=a[i-1]){
            b=a[i];
            }
            x+=a[i];
            }
            zby++;
           if(x>=b*2){
           y++;
           } 
        }
        cout<<y%998244353;
	}
    
    return 0;
    }
