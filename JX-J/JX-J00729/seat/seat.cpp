#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int sum=1;
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            ++sum;
        }
    }
    c=sum/n+1;
    if(c%2==1){
        if(sum%n==0){
            r=n;
        }else{
            r=sum%n;
        }
    }else{
        if(sum%n==0){
            r=1;
        }else{
            r=n-(sum%n)+1;
        }
    }
    cout<<c<<" "<<r;
	return 0;
}
