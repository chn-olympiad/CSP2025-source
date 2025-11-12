#include<bits/stdc++.h>
using namespace std;
	int a[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[109];
	int y=0;
	int o=0;
	for(int i=0;i<n*m;i++){
		cin>>b[y];
		if(i==0){
			o=b[y];
		}
		y++;
	}
	sort(b,b+y);
	int n1=1,m1=1;
	for(int i=n*m-1;i>=0;i--){
		a[n1][m1]=b[i];
		if(b[i]==o){
			cout<<m1<<" "<<n1;
			return 0;
		}
		if(m1%2==0){
			if(n1==1){
				m1++;
			}else{
				n1--;
			}
		}else{
			if(n1==n){
				m1++;
			}else{
				n1++;
			}
		}
		
	}
	return 0;
} 
