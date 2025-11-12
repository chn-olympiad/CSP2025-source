#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,l,h,R;
	cin>>n>>m;
	int a[n*m+1],zw[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(zw,zw+n*m+1);
    for(int i=n*m;i>=1;i--){
    	int f=1;
    	zw[f]=a[i];
    	f++;
	}
	for(int i=1;i<=n*m;i++){
		if(R=zw[i]){
			l=i/n;
			if(i%n>0){
				l+=1;
			}
			if(l%2==1){
				h=i%n;
				break;
			}
			else h=m-i%n+1;
			break;
		}
	}
	if(l==0) cout<<"1 "<<h;
	else cout<<l<<" "<<h;
	return 0;
}
