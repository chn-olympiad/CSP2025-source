#include<bits/stdc++.h>
using namespace std;
	int main(){
	int n,t,max;
	cin>>t;
	for(int q = 0;q<n;q++) {
		int z,y;
		cin>>z>>y;
		for(int j =0;j<y;j++){
			int r;
		}
		int ans = 0;
		freofen("club.in","r"stdin);
		freofen("club.out","w"stdout);
		int a[100001],b[100001],c[100001];
		int a1[100001],b1[100001],c1[100001];
		int a2 = 0,b2 = 0,c2 =0;
		for(int i =0;i<z;i++){
			int m;
			cin>>a[i],b[i],c[i];
			m = max(a[i],b[i],c[i]);
			if(m=a){
				a1[i]=m;
			}else
			if(m=b){
				b1[i]=m;
			}else
			if(m=c){
				c1[i]=m;
			}
		}
		sort(a1,a1+n);
		sort(b1,b1+n);
		sort(c1,c1+n);
		while(n) {
	}
	cout<<ans<<endl;
	}
	}	return 0;
