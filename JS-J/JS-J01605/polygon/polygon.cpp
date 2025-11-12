#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int a[5020];
bool check(long long int sum,long long int max){
	if(sum>2*max) return true;
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		int sum=0;
		int max=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(a[i]>max){
				max=a[i];
			}
		}
		if(check(sum,max)){
			cout<<1<<endl;
			return 0;
		}else{
			cout<<0<<endl;
			return 0;
		}
	}
	return 0;
}
