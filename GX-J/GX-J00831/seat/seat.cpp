#include<bits/stdc++.h>
using namespace std;
int a[300];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	int max=0;
	for(int i=2;i<=n*m;i++){
		if(a[i]>r){
			max++;
		}
	}
	max+=1;
	if(max<=n){
		cout<<1<<' '<<max;
	}else{
		int c=max;
		max=max/n;
		c=c-max*n;
		if(max%2==0){
			if(c==0){
				cout<<1<<' '<<max;
			}else{
				cout<<c<<' '<<max+1;
			}
			
		}else{
			if(c==0){
				cout<<n<<' '<<max;
			}else{
				cout<<n-(c-1)<<' '<<max+1;
			}
		}
	}
	return 0;
}
