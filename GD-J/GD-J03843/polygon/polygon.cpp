#include<bits/stdc++.h>
using namespace std;
int n,sum,i1=0,j1=2;
long long cnt=0;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(i1=0;i1<n-2;i1++){
		for(j1=i1+2;j1<n;j1++){
			for(int i=i1;i<=j1;i++){
				for(int j=i;j<j1-1;j++){
					cnt+=a[j];
					if(cnt>2*a[j1]) sum++;
				}
			}
		}
	}
	sum%=998;
	sum%=244;
	sum%=353;
	cout<<sum;
	return 0;
}
