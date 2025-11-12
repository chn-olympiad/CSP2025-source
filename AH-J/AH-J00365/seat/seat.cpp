#include <bits/stdc++.h>
using namespace std;
int cmp(int p,int q){
    return p>q;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105];
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int xr=a[1];
    sort (a+1,a+n*m+1,cmp);
    int c=0,r=0;
//    for (int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<"\n";
    for (int i=1;i<=n;i++){
		if(i%2!=0) r=0;
		else r=m+1;
		c++;
		bool f=0;
		for (int j=1;j<=m;j++){
			if (i%2!=0) {
				r++;
//			cout<<c<<" "<<r<<"\n";
				if (a[(i-1)*n+r]==xr) {
					
					f=1;
					break;
				}
		    }
		    else {
				r--;
//				cout<<c<<" "<<r<<"\n";
				if (a[(i-1)*n+m-r+1]==xr) {
					f=1;
					break;
				}
			}
		}
		if (f) break;
		
	}
	cout<<c<<" "<<r<<"\n";
    return 0;
}
