#include<iostream>
using namespace std;
long long n,a[5010],p[5010],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]+i;
	}
	if(n<=3){
		if(n!=3)cout<<0;
		else{
			if(a[1]+a[2]+a[3]>=max(a[1],max(a[2],a[3]))){
				cout<<1;
			}
		}
	}
	return 0;
}
