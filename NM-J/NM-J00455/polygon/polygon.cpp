#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=a[i];
		cout<<cnt;
	}else{
		int max1=-1;
		for(int i=1;i<=n;i++){
			max1=max(max1,a[i]);
		}
		cout<<max1;
	}
	return 0;
}
