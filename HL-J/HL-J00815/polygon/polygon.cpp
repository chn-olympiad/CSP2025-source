#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
	freopen("polugon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1||n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		int b=a[1]+a[2]+a[3];
		int c=2*max(a[1],max(a[2],a[3]));
		if(b>c){
			cout<<1;
			return 0;
		}
	}
	return 0;
}

