#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.put","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int h;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
				h=a[j];
				a[j]=a[i];
				a[i]=h;
			}
		}
	} 
	int t=0;
	for(int i=0;i<n;i++){
		int sum=0;
		sum+=a[i];
		for(int j=i+1;j<=n;j++){
			sum+=a[j];
			if(sum>2*a[i]){
				t++;
			}
		}
	}
	cout<<t;
	return 0;
}
