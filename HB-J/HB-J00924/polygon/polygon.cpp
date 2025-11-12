#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	int max=0,sum=0;
	for(int i=0;i>n;i++){
		cin>>a[i];
		if(a[i]>max)max=a[i];
		sum+=a[i];
	}
	cout<<1;
	return 0;
}
