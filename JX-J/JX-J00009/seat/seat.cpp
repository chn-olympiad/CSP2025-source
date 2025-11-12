#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	int s=0;
	sort(a+1,a+1+n*m);
	/*for(int i=1;i<=n*m;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;*/
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				
				//cout<<n*m-s<<' '<<a[n*m-s]<<' '<<i<<' '<<j<<endl;
				if(a[n*m-s]==r){
					cout<<i<<' '<<j;
					return 0;
				}
				s++;
			}
		}else{
			for(int j=n;j>0;j--){
				
				//cout<<n*m-s<<' '<<a[n-s]<<' '<<i<<' '<<j<<endl;
				if(a[n*m-s]==r){
					
					cout<<i<<' '<<j;
					return 0;
				}
				s++;
			}
		}
	}
	
	return 0;
}
