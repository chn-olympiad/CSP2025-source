#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[5000];
int sum[N];
bool check(int sum){
	cout<<sum<<'\n';
}
int main(void){
//freopen("polygon","in","r"stdin);
//freopen("polygon","out","w"stdin);
	int n;
	cin>>n;
	if(n>=20){
	   cout<<n;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
    

	return 0;
}
