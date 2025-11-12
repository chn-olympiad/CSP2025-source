#include<bits/stdc++.h>
using namespace std;
int a[5005],m,m1,n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n>=3){
		for(int w=3;w<=n;w++){
			for(int l=0,r=l+w;l<=n-w;l++){
				for(int i=l;i<=r;i++){
					m1+=a[i];
				}
				if(m1>(a[r]*2)){
					m++;
				}
				m1=0;
			}
		}
	}
	m=m%998244353;
	cout<<m;
	return 0;
} 