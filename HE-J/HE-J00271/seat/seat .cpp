#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1005]={0},n1=1,m1=1;
	double c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];	
	}
	int b=0;
	for(int i=1;i<=n*m;i++){
		if(a[1]<a[i]){
			b++;
		}	
	}
	if(b==0){
		cout<<"1 1";
	}
	else if(b==n*m-1){
		cout<<n<<" "<<m;
	}
	else{
		n1=(b+1)/m+1;
		if((b+1)%m%2==0){
			m1=m-(b+1)%m+1;
			if(m1>m){
				m1-=m;
				n1+1;
			}
		}
		else{
			m1=(b+1)%m;
		if(m1>m){
				m1-=m;
				n1+1;
			}
		}
		cout<<n1<<" "<<m1;
	}
	return 0;
} 
