#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("polygon.in","i",stdin );
	freopen("polygon.out","o",stdout );
	long long n=0,m=0;
	cin>>n;
	vector<long long>a;
	vector<long long>b;
	vector<long long>c;
	a.push_back(0);
	b.push_back(0);
	c.push_back(0);
	for(int i=1;i<=n;i++){
		int t=0;
		cin>>t;
		a.push_back(t+a[i-1]);
		b.push_back(t*2);
		c.push_back(t);
	}
	for(int i=3;i<n;i++){
		for(int j=0;j<=i-3;j++){
			if(a[i]-c[j]>b[i]){
				m++;
			}
		}
	}
	m=m%998;
	m=m%244;
	m=m%353;
	cout<<m;
	
	return 0;
}
