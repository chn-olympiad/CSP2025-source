#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={},cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j>=1;j--){
			sum+=a[j];
			if(sum>a[i]){
				cnt+=(j-1)*(j-1);
			}
		}
	}
	cout<<cnt;
} 