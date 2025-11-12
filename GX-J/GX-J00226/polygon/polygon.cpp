#include<bits/stdc++.h>
using namespace std;
const int N=50000+500;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		cout<<"1";
		return 0;
	}
	sort(a+1,a+n+1);
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i];
		if(ans>=a[i]){
			cnt++;
		}
	}
	cout<<cnt%99844353;
	return 0;
}
