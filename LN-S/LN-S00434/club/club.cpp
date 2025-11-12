#include<bits/stdc++.h>
using namespace std;
int a[100030],b[100030],c[100030],a1[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		if(n==2){
			 a1[1]=a[1]+b[2];
			 a1[2]=a[1]+c[2];
			 a1[3]=c[2]+b[1];
			sort(a1+1,a1+n+1);
			cout << a1[3];
	}
	    if(n==100000){
			int sum=0;
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--){
				sum+=a[i];
			}
			cout << sum;
		}
	}	
	return 0;
}
