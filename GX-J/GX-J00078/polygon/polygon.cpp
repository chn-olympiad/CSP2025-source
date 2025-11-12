#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int cnt=a[n]*2;
	for(int i=0;i<n;i++){
		int let=a[i];
		for(int j=0;j<n;j++){
			if(i!=j&&let<=cnt) let+=a[j];
			else{
				sum++;
				
			}
		}
	}
	cout<<sum;
	return 0;
}
