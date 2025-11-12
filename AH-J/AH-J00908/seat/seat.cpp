#include<bits/stdc++.h>
using namespace std;
long long i,me,m,n,l,h,ans,a[200];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
		cin>>a[i];
    }
    me=a[1];
	sort(a+1,a+n*m+1);
	for(i=n*m;i>=1;i--){
		if(me==a[i]){
			ans=n*m-i+1;
			l=ans/n+1;
			if(ans%n==0){
				l--;
			}
			if(l%2==1){
				h=ans%n;
				if(h==0){
					h=n;
				}
			}else{
				h=n-ans%n+1;
				if(h>n){
					h=h%n;
				}
			}
			break;
		}
	}
	cout<<l<<" "<<h;
    return 0;
}
