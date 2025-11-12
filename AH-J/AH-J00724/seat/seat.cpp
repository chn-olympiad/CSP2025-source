#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[1001],Xr;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> Xr;
	a[1]=Xr;
	for(int i=2;i<=n*m;i++){
	    cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
        if(a[i]==Xr){
            if(i%n==0 && ((i-1)/n+1)%2==0){
                cout << (i-1)/n+1 << " " << 1;
            }
            else if(i%n==0 && ((i-1)/n+1)%2==1){
                cout << (i-1)/n+1 << " " << n;
            }
            else if(i%n==1 && ((i-1)/n+1)%2==0){
               cout << (i-1)/n+1 << " " << (n+1)-(i%n);
            }
            else{
                cout << (i-1)/n+1 << " " << (n+1)-(i%n);
            }
		}
    }
	return 0;
}
