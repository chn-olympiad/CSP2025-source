#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("r","polygon.in",stdin);
	freopen("w","polygon.out",stdout);
	long long n,cnt=0,s=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		long long sum=0;
		for(int j=i;j<n;j++){
			sum+=a[j];
			for(int k=i+1;k<j;k++){
				if(sum-a[k]>a[j]*2) cnt++;
			}
			if(sum>a[j]*2&&j-i>=2)cnt++;
		}
	}
	cout<<cnt;
    return 0;
}

