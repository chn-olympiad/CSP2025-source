#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t,n,s,p,z;
	cin >> t;
	for(int i=1; i<=t; i++){
		int num=0;
		cin >> n;
		s=n/2;
		p=n/2;
		z=n/2;
		for(int k=1; k<=n; k++){
			int a[k];
			for(int j=1; j<=3; j++){
				cin >> a[j];
			}
			if((a[1]>a[2]) && (s!=0)){
				num+=a[1];
				s-=1;
			}
			else if((a[2]>a[1]) && (p!=0)){
				num+=a[2];
				p-=1;
			}
		} 
		cout << num;
	}
	return 0;
}
