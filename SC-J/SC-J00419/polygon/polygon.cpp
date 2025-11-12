#include <bits/stdc++.h>
using namespace std;
long long ji;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[6000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int y=n;
	sort(a,a+n,cmp);
	for(i=0;i<n;i++){
		long long t=a[i];
		for(int j=1;j<n;j++){
			if(a[i]+a[j]>a[i]*2){
				ji++;
			}
		}
	}
	cout<<ji;
	return 0;
}