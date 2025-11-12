#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[n],ans=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	for(int i=0;i<m;i++){
		ans*=(i+1);
	}
	cout<<ans%998244353<<endl;
}
