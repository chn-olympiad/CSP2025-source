#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10010],wo=0,sum=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	wo=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==wo){
			sum=n*m-i;
			break;
		}
	}
	for(int i=0;;i++){
		if(sum>n){
			sum=sum-n;
			continue;
		}else{
			if(i%2==1){
				cout<<i+1<<" "<<n-sum+1;
			}else{
				cout<<i+1<<" "<<sum;
			}
			break;
		}
	}
	return 0;
}
