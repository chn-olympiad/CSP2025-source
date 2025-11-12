#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long cnt;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int sum=a[0]+a[1]+a[2];
		for(int j=3;j<n;j++){
			sum+=a[j];
			if(sum>(a[j]*2)){
				cnt++;
			}
		}
	}
	long long m=((cnt%998)%244)%353;
	cout<<m;
	return 0;
}
