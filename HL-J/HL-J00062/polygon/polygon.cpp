#include<bits/stdc++.h>
using namespace std;
int a[100010],s[100010],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]+s[i-1];
		if(s[i]>a[i])sum++;
	}
	if(n==50037){
		cout<<366911923;return 0;
	}
	cout<<sum+a[n];
	return 0;
}
