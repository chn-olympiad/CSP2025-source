#include<bits/stdc++.h>
using namespace std;
int n,a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
		}
	}
	else{
		int num=0,cnt=0;
		for(int i=1;i<n;i++){
			num+=i;
			cnt+=num;
		}
		cout<<cnt;
	} 
	
}

