#include<bits/stdc++.h>
using namespace std;
long long n,m,r,a[1010],b[1010],num,x[20][20],q,w,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	sort(a+1,a+(n*m)+1);
	for(int i=n*m;i>=1;i--){
		k++;
		b[k]=a[i];
	}
	while(num<n*m){
		num+=n;
		q=1;
		if((num/n)%2!=0){
			for(int i=num-n+1;i<=num;i++){
				x[q][num/n]=b[i];
				q++;				
			}
		}else{
			for(int i=num;i>=num-n+1;i--){
				x[q][num/n]=b[i];
				q++;				
			}			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i][j]==r){
				cout<<j<<" "<<i<<"\n";
			}
		}
	}
	return 0;
}
