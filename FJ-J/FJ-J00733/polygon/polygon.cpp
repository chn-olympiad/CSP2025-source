#include <bits/stdc++.h>
using namespace std;
int n;
int sum,mx,cnt;
int a[1000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		if(sum>mx*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		int temp=1;
		for(int i=1;i<=n-2;i++){
			cnt+=temp;
			temp+=3*i;
		}
		cout<<cnt;
	}
	return 0;
}
