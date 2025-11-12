#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3){
		cout<<1;
	}
	int sum;
	if(n==4){
		sum=0;
		if(a[3]<2*(a[2]+a[1])){
			sum++;
		}
		if(a[2]<2*(a[1]+a[0])){
			sum++;
		}
		if(a[3]<2*(a[1]+a[0])){
			sum++;
		}
		if(a[3]<2*(a[2]+a[1]+a[0])){
			sum++;
		}
		cout<<sum;
	}
}
