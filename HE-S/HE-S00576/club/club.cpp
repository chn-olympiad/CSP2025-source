#include <bits/stdc++.h>
using namespace std;
int main(){
int n,t;
int a[n];
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
    cin >> t;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	int b=0,c=0,m=0;
	for (int i=1;i<=t;i++){
		for (int j=1;j<=n;j++){
			if (a[i]>=a[i+1] && a[i]>=a[i+2]){
				b=1;
				c+=a[i];
				cout << c;
				if (b+=b>=n/2){
					if (a[i+1]>=a[i+2]){
						b=2;
						m+=a[i+1];
						cout << m;
					}else{
						b=2;
						m+=a[i+2]; 
						cout << m;
					}
				}
			}
			if (a[i+1]>=a[i] && a[i+1]>=a[i+2]){
				b=2;
				c+=a[i+1];
				cout << c;
				if ((b+=b)/2>=n/2){
					if (a[i+2]>=a[i+1]){
						b=3;
						c+=a[i+2];
						cout << m;
					}else{
						b=2;
						c+=a[i];
						cout << m;
					}
				}
			}
			if (a[i+2]>=a[i] && a[i+2]>=a[i+1]){
				b=3;
				c+=a[i+2];
				cout << c;
				if ((b+=b)/3>=n/2){
					if (a[i]>=a[i+1]){
						b=1;
						c+=a[i];
						cout << m;
					}else{
						b=2;
						c+=a[i+1];
						cout << m;
					}
				}
			}
		}
	}
	cout << c;
	return 0;
	//±£´æÊ± ½â×¢ÊÍ 
}
