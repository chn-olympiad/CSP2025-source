#include<bits/stdc++.h>
using namespace std;
int n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;

	if(n==3){
		int x,y,z;
		cin >>x>>y>>z;
		if(x+y>z||x+z>y||y+z>z){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	long long a[n+1];
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	sort(a,a+n,cmp);
	long long ans=0,sum=0;
	for(int i=2;i<n;i++){
		sum=0;
		for(int j=0;j<=i;j++){
			sum+=a[j];
		}
		if(sum>a[i]*2){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
