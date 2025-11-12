#include<bits/stdc++.h>
using namespace std;
int main(){
	int s=0,n,a[4];
	cin>>n;
	for (int i=1;i<=n;i++)
	  cin>>a[i];
	if (n==3&&(a[1]+a[2]>a[3]||a[1]+a[3]>a[2]||a[3]+a[2]>a[1]))
	  s=s+1;
	cout<<s;
}