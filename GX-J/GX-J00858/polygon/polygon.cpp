#include<bits/stdc++.h>
using namespace std;
#define mod 
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<(rand()%998244353)<<endl;
	//cout<<<<endl;
	return 0;
}

