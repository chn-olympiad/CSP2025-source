#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num1,num2,R,ans=1,c,r,l;
bool cmp(int x,int y){
    return x>y;
}int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    num1=n*m;
    num2=2*n;
    for(int i=1;i<=num1;i++){
        cin>>a[i];
        if(i!=1){
            if(a[i]>a[1]){
                ans++;
            }
        }
    }if(ans%n==0){
        c=ans/n;
    }else{
        c=ans/n+1;
    }l=ans%num2;
    if(l==0){
		r=1;
	}else{
		if(l<=n){
			r=l;
		}else{
			r=n-l%n+1;
		}
	}cout<<c<<" "<<r;
	return 0;
}
