#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m,c=1,r=1,h,a[120];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
        cin>>a[i];
	}
	h=a[0];
	sort(a,a+n*m);

	for(int i=n*m-1;i>=0;i--){
        if(a[i]==h){
            cout<<c<<' '<<r;
            return 0;
        }if(c%2==1){
            r++;
        }if(c%2==0){
            r--;
        }if(r>n){
            c++;
            r--;
        }if(r<1){
            c++;
            r++;
        }
    }

	return 0;
}
