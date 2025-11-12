#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],b[109];
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	int q=1;
	for(int i=1;i<=k;i++){
		int f;
		cin>>f;
		b[f]++;
		if(i==1){
			r=f;
		}
	}
	for(int i=100;i>=1;i--){
		if(b[i]>=1){
			while(b[i]!=0){
				a[q] = i;
				b[i]--;
				q++;
			}
		}
	}
	
//	for(int i=1;i<q;i++){
//		cout<<a[i]<<" ";
//	}


	int op=1;
	for(int i=1;i<=m;i++){
		
		if(i%2 == 1){
			for(int j=1;j<=n;j++){
//				cout<<a[op]<<" "<<op<<" ";
				if(a[op]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				op++;
				
			}
		}
		if(i%2 == 0){
			for(int j=n;j>=1;j--){
//				cout<<a[op]<<" "<<op<<" ";
				if(a[op]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				
				op++;
				
			}
		}
	}
	
}
