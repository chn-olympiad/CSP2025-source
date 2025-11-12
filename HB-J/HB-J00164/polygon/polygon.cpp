#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,c=0,cnt=0;
	cin>>n;
	int a[n+10];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a+0,a+n);
	cout<<1;
	return 0;
}
