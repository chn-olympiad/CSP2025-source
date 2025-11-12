#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	if(n<=2){
		cout<<"0";
		return 0;
	}
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	if(n==3){
		if(a[1]+a[2]>a[0]){
			cout<<"1";
			return 0;
		}
		else {
			cout<<"0";
			return 0;
		}
	}
	long long sum=0;
	for(int i=1;i<n;i++)
	{
		sum+=a[i];
	}
	if(sum<a[0]*2){
		cout<<"0";
	}
	return 0;
}